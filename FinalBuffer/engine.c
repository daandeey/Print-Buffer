#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>


#define for_each_item(item, list) \
    for(T * item = list->head; item != NULL; item = item->next)
#define THICK 6
#define SIZE 60

//Global variables
struct fb_var_screeninfo vinfo;
struct fb_fix_screeninfo finfo;
long int screensize = 0;
char *fbp = 0;
long int location = 0;
int fbfd = 0;

void initFbp(){
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((long)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
}

void fillPixel(int x, int y, int r, int g, int b, int t){
    location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                        (y+vinfo.yoffset) * finfo.line_length;
            
            *(fbp + location) = b;
            *(fbp + location + 1) = g;
            *(fbp + location + 2) = r;
            *(fbp + location + 3) = t;
}

void clearBackground() {
    // Melakukan reset warna pada screen dengan warna hitam dengan resolusi 1280x720
    for(int a=0; a<720;a++){
        for(int b=0; b<1280;b++){
            fillPixel(b, a, 0, 0, 0, 0);
        }
    }
}

void printGaris(int x0, int y0, int x1, int y1, int r, int g, int b, int t)
{
    //Mencetak garis dari titik <x0, y0> ke <x1, y1>
    int x, y;
    double m;
    int tempX, tempY;

    
    //traversal X
    if (x0 > x1)
    {
        tempX = x0;
        x0 = x1;
        x1 = tempX;

        tempY = y0;
        y0 = y1;
        y1 = tempY;
    }

    m = (double) (y1 - y0)/(x1 - x0);

    x = x0;
    y = y0;

    for (x = x0; x < x1; x++)
    {
        y = y0 + (x-x0) * m;
        fillPixel(x, y, r, g, b, t);
    }

    //traversal Y
    if (y0 > y1)
    {
        tempX = x0;
        x0 = x1;
        x1 = tempX;

        tempY = y0;
        y0 = y1;
        y1 = tempY;
    }

    m = (double) (x1 - x0)/(y1 - y0);


    for (y = y0; y < y1; y++)
    {
        x = x0 + (y-y0) * m;
        fillPixel(x, y, r, g, b, t);
    }
}

void floodFill(int x, int y, int br, int bg, int bb, int bt, int fr, int fg, int fb, int ft)
{
    /*
        Melakukan floodfill di titik <x, y> dengan fill color <fr, fg, fb, ft> pada bidang yang memimiliki border color <br, bg, bb, bt>
    */

    int lr, lg, lb, lt;

    if ((x >= 0) && (x < 1280) && (y >= 0) && (y < 720))
    {
        location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
        lr = *(fbp + location + 2);
        lg = *(fbp + location + 1);
        lb = *(fbp + location);
        lt = *(fbp + location + 3);

        if ((lr == br) && (lg == bg) && (lb == bb) && (lt == bt))
        {
            fillPixel(x, y, fr, fb, fb, ft);

            floodFill(x, y-1, br, bg, bb, bt, fr, fg, fb, ft);
            floodFill(x-1, y, br, bg, bb, bt, fr, fg, fb, ft);
            floodFill(x+1, y, br, bg, bb, bt, fr, fg, fb, ft);
            floodFill(x, y+1, br, bg, bb, bt, fr, fg, fb, ft);
        }
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
                    for (int i = x0; i <= x1; i++)
                    {
                        fillPixel(i, y, r, g, b, t);
                    }                    
                    count = 0;
                }
                
            }

        }
    }
}