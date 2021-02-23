#include "../includes/fractol.h"

int main(int ar, char **av)
{
    t_windows	win;

    (void)av;
    (void)ar;
    /*if (ar <= 1)
    {
        ft_printf("Usage ./fractol ");
        return (0);
    }*/
    init_windows(&win);
    draw_new_map(&win);
    mlx_key_hook(win.windows, ft_event, &win);
	mlx_hook(win.windows, 2, 0, ft_event, &win);
    mlx_loop(win.graph_id);
    return (0);
}
