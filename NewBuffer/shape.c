#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>
#include "engine.c"

#define PI 3.14159265

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

void printLingkaran(int xp, int yp, int z, int r, int g, int b, int t)
{
    //Mencetak lingkaran dengan titik pusat <xp, yp> dan jari-jari Z
    int x, x1, x2;
    int y, y1, y2;

    for (x = xp - z; x <= xp + z; x++)
    {
        y1 = yp + sqrt(pow(z, 2) - pow(x - xp, 2));
        y2 = yp - sqrt(pow(z, 2) - pow(x - xp, 2));

        fillPixel(x, y1, r, g, b, t);
        fillPixel(x, y2, r, g, b, t);
    }

    for (y = yp - z; y <= yp + z; y++)
    {
        x1 = xp + sqrt(pow(z, 2) - pow(y - yp, 2));
        x2 = xp - sqrt(pow(z, 2) - pow(y - yp, 2));

        fillPixel(x1, y, r, g, b, t);
        fillPixel(x2, y, r, g, b, t);
    }
}

void printPoligon(int xp, int yp, int n, int p, int q, int deg, int r, int g, int b, int t)
{
    //Mencetak segi-N dengan titik pusat <xp, yp>, panjang p dan lebar q

    int x, y;
    int x1, y1, x2, y2;
    double d;

    d = -90 + deg;
    x1 = xp + q * cos(d * PI / 180);
    y1 = yp + p * sin(d * PI / 180);

    for (d = (360/n) - 90 + deg; d <= 270 + deg; d += 360/n)
    {
        x2 = xp + q * cos(d * PI / 180);
        y2 = yp + p * sin(d * PI / 180);

        printGaris(x1, y1, x2, y2, r, g, b, t);

        x1 = x2;
        y1 = y2;
    }
}

void printElips(int xp, int yp, int p, int q, int r, int g, int b, int t)
{
    //Mencetak elips dengan titik pusat <xp, yp> dengan jari-jari <p, q>
    int x, x1, x2;
    int y, y1, y2;

    for (x = xp - p; x <= xp + p; x++)
    {
        y1 = yp + sqrt( (pow(p, 2) - pow(x - xp, 2)) * pow((double) q/p, 2));
        y2 = yp - sqrt( (pow(p, 2) - pow(x - xp, 2)) * pow((double) q/p, 2));

        fillPixel(x, y1, r, g, b, t);
        fillPixel(x, y2, r, g, b, t);
    }

    for (y = yp - q; y <= yp + q; y++)
    {
        x1 = xp + sqrt((pow(q, 2) - pow(y - yp, 2)) * pow((double) p/q, 2));
        x2 = xp - sqrt((pow(q, 2) - pow(y - yp, 2)) * pow((double) p/q, 2));

        fillPixel(x1, y, r, g, b, t);
        fillPixel(x2, y, r, g, b, t);
    }
}

void printPersegiPanjang(int x1, int y1, int x2, int y2, int r, int g, int b, int t)
{
    //Mencetak persegi panjang dengan titik awal <x1, y1> ke titik akhir <x2, y2>
    printGaris(x1, y1, x2, y1, r, g, b, t);
    printGaris(x1, y1, x1, y2, r, g, b, t);
    printGaris(x1, y2, x2, y2, r, g, b, t);
    printGaris(x2, y1, x2, y2, r, g, b, t);
}

void printPersegi(int x, int y, int d, int r, int g, int b, int t)
{
    //Mencetak persegi dengan titik awal <x, y> dengan panjang sisi d 
    printPersegiPanjang(x, y, x + d, y + d, 255, 255, 255, 0);
}

void printSegitiga(int x1, int y1, int x2, int y2, int x3, int y3, int r, int g, int b, int t)
{
    //Mencetak segitiga berdasarkan masukan tiga titik
    printGaris(x1, y1, x2, y2, r, g, b, t);
    printGaris(x1, y1, x3, y3, r, g, b, t);
    printGaris(x2, y2, x3, y3, r, g, b, t);

}

void printTank(int x, int y, int len, int r, int g, int b, int t) {
    int tinggi_kepala = floor(0.75 * len);
    int y0 = y - ceil(sqrt(3) / 2 * len);

    printPoligon(x, y, 6, len, len * 3, 30, r, g, b, t); //Print Badan Tank
    printPersegiPanjang(x - len, y0 - tinggi_kepala, x + len, y0, r, g, b, t); //Print Kepala Tank
    printPersegiPanjang(x + len, y0 - floor(0.6 * tinggi_kepala), x + 3 * len, y0 - floor(0.4 * tinggi_kepala), r, g, b, t); //Print Tembakan Tank
}

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
    if ((int)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

    clearBackground();

    //Begin Draw

    // printSegitiga(100, 100, 150, 175, 250, 400, 255, 255, 255, 0);
    // printPersegiPanjang(75, 30, 125, 55, 255, 255, 255, 0);
    // printPersegiPanjang(125, 40, 175, 45, 255, 255, 255, 0);
    // printPoligon(100, 100, 6, 50, 30, 255, 255, 255, 0);
    // printPersegi(100, 100, 500, 255, 255, 255, 0);
    printTank(500, 500, 25, 255, 255, 255, 0);
    //End Draw


	
    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}