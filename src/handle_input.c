#include "ft_ssl.h"

int		get_command(char *cmd)
{
	int i;

	i = -1;
	while (g_ssl_dp[++i].command)
		if(ft_strcmp(g_ssl_dp[i].command, cmd) == 0)
			break;
	if (!g_ssl_dp[i].command)
		error_exit(E_COMMAND, cmd);
	return i;
}

void	flag_handler(char c, t_ssl *ssl, int *ac)
{
	static int	call = 0;

	if (call++ == 0)
	{
		ssl->flags.p = 0;
		ssl->flags.q = 0;
		ssl->flags.r = 0;
	}
	if (c == 'p')
		ssl->flags.p = 1;
	else if (c == 'q')
		ssl->flags.q = 1;
	else if (c == 'r')
		ssl->flags.r = 1;
	if (ssl->flags.r && ssl->flags.q)
		ssl->flags.r = 0;
	*ac -= 1;
}

void	stdin_mode(int ac, t_ssl *ssl)
{
	char	*input;
	char	*tmp;

	if ((ssl->flags.p || ac == 2) && get_next_line(0, &tmp) > 0)
	{
		input = ft_strjoin(tmp, "\n");
		free(tmp);
		ssl->flags.p ? FP("%s", input) : 0;
		ssl->dp.f(input);
		FP("\n");
		free(input);
	}
}

void	file_mode(int fd, t_ssl *ssl, char *file)
{
	char	*tmp;
	char	*input;

	if (get_file(fd, &tmp) >= 0)
	{
		input = ft_strjoin(tmp, "\n");
		free(tmp);
		tmp = ft_strdup(ssl->dp.command);
		!ssl->flags.q && !ssl->flags.r ?
			FP("%s(%s)= ", ft_str_upper(tmp), file) : 0;
		ssl->dp.f(input);
		ssl->flags.r ? FP(" %s", file) : 0;
		FP("\n");
		free(input);
		free(tmp);
		ssl->is_file_read = 1;
	}
	else
		error_alert(E_FOLDER, file);
	close(fd);
}

void	handle_input(int i, int ac, char *av[], t_ssl *ssl)
{
	int		fd;
	char	*tmp;

	stdin_mode(ac, ssl);
	while (av[i])
	{
		if (ssl->is_file_read == 0 && ft_strcmp(av[i], "-s") == 0)
		{
			tmp = ft_strdup(ssl->dp.command);
			if (!ssl->flags.q && !ssl->flags.r)
				FP("%s (\"%s\") = ", ft_str_upper(tmp), av[++i]);
			else
				i++;
			ssl->dp.f(av[i]);
			ssl->flags.r ? FP(" %s", av[i]) : 0;
			FP("\n");
			free(tmp);
		}
		else if ((fd = open(av[i], O_RDONLY)) > 0)
			file_mode(fd, ssl, av[i]);
		else
			error_alert(E_INPUT, av[i]);
		i++;
	}
}
