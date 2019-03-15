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

void floodFillPixel(int x, int y, int r0, int g0, int b0, int t0, int r1, int g1, int b1, int t1)
{
    location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
    if (((*(fbp + location) == b0) && (*(fbp + location + 1) == g0) && (*(fbp + location + 2) == r0) && (*(fbp + location + 3) == t0)))
    {
        fillPixel(x, y, r1, g1, b1, t1);

        /*
        floodFillPixel(x-1, y-1, r0, g0, b0, t0, r1, g1, b1, t1);
        floodFillPixel(x, y-1, r0, g0, b0, t0, r1, g1, b1, t1);
        floodFillPixel(x+1, y-1, r0, g0, b0, t0, r1, g1, b1, t1);

        floodFillPixel(x-1, y, r0, g0, b0, t0, r1, g1, b1, t1);
        floodFillPixel(x+1, y, r0, g0, b0, t0, r1, g1, b1, t1);

        floodFillPixel(x-1, y+1, r0, g0, b0, t0, r1, g1, b1, t1);
        floodFillPixel(x, y+1, r0, g0, b0, t0, r1, g1, b1, t1);
        floodFillPixel(x+1, y+1, r0, g0, b0, t0, r1, g1, b1, t1);
        */

        floodFillPixel(x, y-1, r0, g0, b0, t0, r1, g1, b1, t1);
        floodFillPixel(x-1, y, r0, g0, b0, t0, r1, g1, b1, t1);
        floodFillPixel(x+1, y, r0, g0, b0, t0, r1, g1, b1, t1);
        floodFillPixel(x, y+1, r0, g0, b0, t0, r1, g1, b1, t1);




    }
}

void clearBackground() {
    for(int a=0; a<720;a++){
        for(int b=0; b<1280;b++){
            fillPixel(b, a, 0, 0, 0, 0);
        }
    }
}