#include "../includes/fractol.h"

void    setup_mandelbrot(t_mandelbrot *m)
{
    ft_bzero(m, sizeof(t_windows));
    m->x1 = -2.1;
    m->x2 = 0.6;
    m->y1 = -1.2;
    m->y2 = 1.2;
    m->i = 50;
}

void	init_windows(t_windows *w)
{
	ft_bzero(w, sizeof(t_windows));
	if (!(w->graph_id = mlx_init()))
		exit(1);
	w->windows = mlx_new_window(w->graph_id, LONGUEUR, LARGEUR, "FDF");
}