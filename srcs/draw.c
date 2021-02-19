#include "../includes/fractol.h"

void		draw_pixel(int x, int y, t_windows *window, int color)
{
	int pixel;
	int hex;

	hex = color;
	if (window && x >= 0 && y >= 0 && x < LONGUEUR && y < LARGEUR)
	{
		pixel = (x * 4) + (4 * LONGUEUR * y);
		window->img_str[pixel] = (hex / 64) + 10;
		window->img_str[pixel + 1] = (hex / 32) + 10;
		window->img_str[pixel + 2] = (hex / 16) + 10;
	}
}

void draw_new_map(t_windows *w, t_mandelbrot *m)
{
	int bpp;
	int s_l;
	int endian;

	w->img_ptr = mlx_new_image(w->graph_id, LONGUEUR, LARGEUR);
	w->img_str = (unsigned char*)mlx_get_data_addr(w->img_ptr, &bpp, &s_l,
		&endian);
	mandelbrot(w, m);
	mlx_put_image_to_window(w->graph_id, w->windows, w->img_ptr, 0, 0);
}
