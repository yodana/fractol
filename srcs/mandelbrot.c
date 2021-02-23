#include "../includes/fractol.h"

void    is_borned(int x, int y, t_windows *w, t_mandelbrot *m)
{
    int i;
    double z_r;
    double z_i;
    double tmp;

    z_r = 0;
    z_i = 0;
    i = 0;
    while (i <= m->i)
    {
        tmp = z_r;
       // z_r = pow(z_r, 2) - pow(z_i, 2) + (x / LONGUEUR + m->x1);
        z_r = pow(z_r, 2) - pow(z_i, 2) + (x / ((LONGUEUR * m->z) / (fabs(m->x1) + fabs(m->x2))) + m->x1);
       // z_i = 2 * tmp * z_i + (y / LARGEUR + m->y1);
        z_i = 2 * tmp * z_i + (y / ((LARGEUR * m->z) / (fabs(m->y1) + fabs(m->y2))) + m->y1);
        if (pow(z_r, 2) + pow(z_i, 2) >= 4)
        {
            draw_pixel(x, y, w, (i * 255));
            return ;
        }
        i++;
    }
    draw_pixel(x, y, w, (i * 255) / 50);
}

void mandelbrot(t_windows *w, t_mandelbrot *m)
{
    int x;
    int y;
 
    x = 0;
    y = 0;

    while (x <= (LONGUEUR))
    {
        while (y <= (LARGEUR))
        {
            is_borned(x, y, w, m);
            y++;
        }
        x++;
        y = 0;
    }
}