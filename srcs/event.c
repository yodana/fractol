#include "../includes/fractol.h"

void zoom(t_windows *w, t_mandelbrot *m)
{
  //  m->x2 = m->x2 - 0.01;
   // m->y2 = m->y2 - 0.01;
    m->x1 = m->x1 + 0.01;
    m->y2 = m->y2 - 0.01;
    mlx_clear_window(w->graph_id, w->windows);
	mlx_destroy_image(w->graph_id, w->img_ptr);
    draw_new_map(w, m);
}

int ft_event(int key, t_windows *w, t_mandelbrot *m)
{
    if (key == 44)
        zoom(w, m);
    if (key == 53)
	{
		mlx_clear_window(w->graph_id, w->windows);
		mlx_destroy_window(w->graph_id, w->windows);
		exit(0);
	}
    return (0);
}