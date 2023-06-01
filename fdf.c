#include "fdf.h"
// #include "./get_next_line/get_next_line_bonus.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		i;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1900, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1900, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	i = 0;
	while (i <= 500)
	{
		my_mlx_pixel_put(&img, 70, i, 0x00FFFF0);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

// int main(void)
// {
// 	char *str;
// 	char **s;
// 	int fd;

// 	fd = open("basictest.fdf", O_RDONLY);
// 	str = "";
// 	while (str)
// 	{
// 		str = get_next_line(fd);
// 		if (str)
// 		{
// 			s = ft_split(str, ' ');
// 			printf("[%s]\n", str);
// 			printf("{%s}\n", s[9]);
// 		}
// 	}
// 	return (0);
// }