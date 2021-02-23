#include "../includes/fractol.h"

void zoom(t_windows *w, t_mandelbrot *m)
{
    (void)m;
    (void)w;
    mlx_clear_window(w->graph_id, w->windows);
	mlx_destroy_image(w->graph_id, w->img_ptr);
    m->h = m->h / 10;
    m->x1 = 0.3 - m->h;
    m->y2 = -0.3 + m->h;
    m->x2 = 0.3 - m->h;
    m->y1 = -0.3 - m->h;
    // faire un h plus petit a chaque fois qui diminue le point
    //m->i = m->i + 10;
    m->z = m->z + 0.1;
   draw_new_map(w);
}

int ft_event(int key, t_windows *w)
{
    if (key == 44)
        zoom(w, w->m);
    if (key == 53)
	{
		mlx_clear_window(w->graph_id, w->windows);
		mlx_destroy_window(w->graph_id, w->windows);
		exit(0);
	}
    return (0);
}