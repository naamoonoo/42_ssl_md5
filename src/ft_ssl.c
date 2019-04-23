#include "ft_ssl.h"

int	main(int ac, char *av[])
{
	t_ssl	ssl;
	int		i;

	if (ac == 1)
		error_exit(E_USAGE, NULL);
	ssl.dp = g_ssl_dp[get_command(av[1])];
	i = 2;
	while (av[i] && ft_start_with(av[i], '-') && (*(av[i] + 1) != 's'))
		flag_handler(*(av[i++] + 1), &ssl, &ac);
	handle_input(i, ac, av, &ssl);


	// while (1)
	// 	sleep(1);
	return (0);
}
