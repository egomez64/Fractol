#include "fractol.h"
#include <stdio.h>

int    get_color(int iter)
{
    int index;
    unsigned int color_palette[4];

    color_palette[0] = 0xfff30dea;
    color_palette[1] = 0xff00a316;
    color_palette[2] = 0xffefc80a;
    color_palette[3] = 0xff1019ff;
    index = iter % 4;
    return (color_palette[index]);
}