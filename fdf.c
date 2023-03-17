#include "./mlx_linux/minilibx-linux/mlx.h"
#include "./include/fdf.h"
#include "./get_next_line/get_next_line_bonus.h"

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

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	int		i;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	i = 500;
// 	while (i <= 1000)
// 	{
// 		my_mlx_pixel_put(&img, i, i, 0x00FFFF0);
// 		i++;
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }


int	main(void)
{
	int		fd;

	fd = open("basictest.fdf", O_RDONLY);
	if (fd)
		printf("salut");
	get_next_line(fd);
	return (0);
}