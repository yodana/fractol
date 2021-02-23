#include "../includes/fractol.h"

t_mandelbrot   *setup_mandelbrot()
{
    t_mandelbrot *m;

    if (!(m = (t_mandelbrot*)malloc(sizeof(t_mandelbrot))))
        exit(0);
  // ft_bzero(m, sizeof(t_mandelbrot));
    m->x1 = -2.1; 
    m->x2 = 0.6;
    m->y1 = -1.2;
    m->y2 = 1.2;
    m->i = 100;
    m->z = 1;
    m->h = 1;
    return (m);
}

void	init_windows(t_windows *w)
{
	ft_bzero(w, sizeof(t_windows));
    w->m = setup_mandelbrot();
	if (!(w->graph_id = mlx_init()))
		exit(1);
	w->windows = mlx_new_window(w->graph_id, LONGUEUR, LARGEUR, "FDF");
}