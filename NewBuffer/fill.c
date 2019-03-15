#include "shape.c"

void floodFillPixel(int x, int y, int r0, int g0, int b0, int t0, int r1, int g1, int b1, int t1)
{
    location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
    if (((*(fbp + location) == b0) && (*(fbp + location + 1) == g0) && (*(fbp + location + 2) == r0) && (*(fbp + location + 3) == t0)))
    {
        fillPixel(x, y, r1, g1, b1, t1);

        floodFillPixel(x, y-1, r0, g0, b0, t0, r1, g1, b1, t1);
        floodFillPixel(x-1, y, r0, g0, b0, t0, r1, g1, b1, t1);
        floodFillPixel(x+1, y, r0, g0, b0, t0, r1, g1, b1, t1);
        floodFillPixel(x, y+1, r0, g0, b0, t0, r1, g1, b1, t1);




    }
}

void scanFill(int r, int g, int b, int t)
{
    int i, j;
    int x, y;
    int x0, x1;
    int count;

    for (y = 0; y < 720; y++)
    {
        count = 0;
        for (x = 0; x < 1280; x++)
        {
            location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
            if (((*(fbp + location) == b) && (*(fbp + location + 1) == g) && (*(fbp + location + 2) == r) && (*(fbp + location + 3) == t)))
            {
                if (count == 0)
                {
                    x0 = x;
                    count = 1;
                }
                else
                {
                    x1 = x;
                    printGaris(x0, y, x1, y, r, g, b, t);
                    count = 0;
                }
                
            }

        }
    }
}