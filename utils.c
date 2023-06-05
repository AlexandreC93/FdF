#include "fdf.h"

void	ft_return_error(const char *err_msg, int system_function)
{
	if (!system_function)
		ft_putendl_fd(err_msg, STDERR_FILENO);
	else
		perror(err_msg);
	exit(-1);
}