#include "shape.c"

int maskArea(int x, int y, int xmin, int ymin, int xmax, int ymax)
{
    int area = 0;

    if (x < xmin)
    {
        area += 8; //1XXX
    }

    if (x > xmax)
    {
        area += 4; //X1XX
    }

    if (y < ymin)
    {
        area += 2; //XX1X
    }

    if (y > ymax) //XXX1
    {
        area += 1;
    }

    return area;
}

void CohenSutherlandClip(int xmin, int ymin, int xmax, int ymax)
{
    int x1, y1, x2, y2;
    int a1, a2, a_out;
    int n, temp;
    int x, y;
    int flag;

    if (xmin > xmax)
    {
        temp = xmin;
        xmin = xmax;
        xmax = temp;
    }

    if (ymin > ymax)
    {
        temp = ymin;
        ymin = ymax;
        ymax = temp;
    }

    printf("Jumlah garis : ");
    scanf("%d", &n);

    printPersegiPanjang(xmin, ymin, xmax, ymax, 0, 128, 0, 0);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        a1 = maskArea(x1, y1, xmin, ymin, xmax, ymax);
        a2 = maskArea(x2, y2, xmin, ymin, xmax, ymax);

        if (!(a1 & a2)) //Tidak berada di region yang sama
        {
            if ((a1 == 0) && (a2 == 0))
            {
                printGaris(x1, y1, x2, y2, 255, 255, 255, 0);
            }
            else{
                if (a1 != 0)
                {
                    a_out = a1;
                }
                else
                {
                    a_out = a2;
                }
                
            }
        }
        

    }
}