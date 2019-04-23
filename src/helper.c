#include "ft_ssl.h"

void	error_alert(int code, char *input)
{
	if (code == E_INPUT)
		FP("ft_ssl: %s: No such file or directory\n", input);
	else if (code == E_FOLDER)
		FP("ft_ssl: %s: Is a directory\n");
}

void	error_exit(int code, char *input)
{
	if (code == E_USAGE)
		FP("usage: ft_ssl command [command opts] [command args]");
	else if (code == E_COMMAND)
	{
		FP("ft_ssl: Error: '%s' is an invalid command.\n", input);
		FP("Standard commands:\nMessage Digest commands:\nmd5\nsha256\n");
	}
	else if (code == E_FLAG)
	{
		FP("ft_ssl: illegal option -- %s\n", input);
		FP("usage: ft_ssl [-pqr] [-s string] [files ...]");
	}
	exit(-1);
}

void	reverse_bits(uint *c)
{
	uint t;

	t = 0;
	t += *c & 0xff;
	t = t << 8;
	t += (*c >> 8) & 0xff;
	t = t << 8;
	t += (*c >> 16) & 0xff;
	t = t << 8;
	t += (*c >> 24) & 0xff;
	*c = t;
}
