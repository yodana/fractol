#include "../includes/fractol.h"

int main()
{
    t_windows	win;
    t_mandelbrot m;

    setup_mandelbrot(&m);
    init_windows(&win);
    draw_new_map(&win, &m);
    mlx_key_hook(win.windows, ft_event, &win);
	mlx_hook(win.windows, 2, 0, ft_event, &win);
    mlx_loop(win.graph_id);
    return (0);
}
