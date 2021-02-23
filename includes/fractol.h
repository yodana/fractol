#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# define LARGEUR 240
# define LONGUEUR 270
# define ZOOM 250
# include <math.h>

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct		s_mandelbrot
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				i;
	double			z;
	double			h;
}					t_mandelbrot;

typedef struct		s_windows
{
	void			*graph_id;
	void			*windows;
	void			*img_ptr;
	unsigned char	*img_str;
	int				width;
	int				height;
	int				color;
	t_mandelbrot	*m;
}					t_windows;

void	init_windows(t_windows *w);
t_mandelbrot	*setup_mandelbrot();
int		ft_event(int key, t_windows *w);
void	draw_new_map(t_windows *w);
void	mandelbrot(t_windows *w, t_mandelbrot *m);
void	draw_pixel(int x, int y, t_windows *window, int color);
#endif