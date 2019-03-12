#include "framebuffer.h"

// Initialize framebuffer
void initFbp() {
	// Open the file for reading and writing
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Figure out the size of the screen in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((long)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

    clearBackground();
}

// Close framebuffer
void closeFbp() {
	munmap(fbp, screensize);
    close(fbfd);
}

// Fill pixel in location x and y with color r, g, b and t
void fillPixel(int x, int y, int r, int g, int b, int t) {
	long location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
	*(fbp + location) = b;
	*(fbp + location + 1) = g;
	*(fbp + location + 2) = r;
	*(fbp + location + 3) = t;
}

// Flood fill pixel in location x and y with color r, g, b and t
void floodFillPixel(int x, int y, int r0, int g0, int b0, int t0, int r1, int g1, int b1, int t1)
{
    long location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
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

// Clear Background
void clearBackground() {
    for(int a=0; a<SCREEN_HEIGHT;a++){
        for(int b=0; b<SCREEN_WIDTH;b++){
            fillPixel(b, a, 0, 0, 0, 0);
        }
    }
}