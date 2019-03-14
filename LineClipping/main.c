#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>
#include "animation.c"

int main(){

    int x = 0, y = 0;
    long int location = 0;

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

    // Begin Draw

    perbesarBangunan(625, 285, 0.500, 255, 141, 53, 0, 1.75, 1);
    putarMatahari(750, 100, 10, 50, 50, 0, 255, 255, 0, 0, 100, 1);
    geserTank(300, 500, 25, 0, 100, 0, 0, 100, 0, 1);
    geserBullet(500, 470, 5, 3, 143, 188, 143, 0, 50, 0, 1);
    geserPesawat(400, 160, 0.75, 0, 0, 139, 0, 75, 0, 1);
    geserRudal(400, 225, 1, 3, 95, 158, 160, 0, 0, 100, 1);

    // End Draw

    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}