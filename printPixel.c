/*
To test that the Linux framebuffer is set up correctly, and that the device permissions
are correct, use the program below which opens the frame buffer and draws a gradient-
filled red square:
retrieved from:
Testing the Linux Framebuffer for Qtopia Core (qt4-x11-4.2.2)
http://cep.xor.aps.anl.gov/software/qt4-x11-4.2.2/qtopiacore-testingframebuffer.html
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>
#include "alphabet.h"

#define PI 3.14159265
#define THICK 6
#define SIZE 60
#define for_each_item(item, list) \
    for(T * item = list->head; item != NULL; item = item->next)

//Global variables
struct fb_var_screeninfo vinfo;
struct fb_fix_screeninfo finfo;
long int screensize = 0;
char *fbp = 0;
long int location = 0;
int fbfd = 0;

void initFbp(){
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((int)fbp == -1) {
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

void printGaris(int x0, int y0, int x1, int y1, int r, int g, int b, int t) {
    int dx, dy, p, x, y, i;
    int tempX, tempY;

    if (x0>x1)
    {
        tempX = x0;
        x0 = x1;
        x1 = tempX;

        tempY = y0;
        y0 = y1;
        y1 = tempY;
    }
 
	dx=x1-x0;
	dy=y1-y0;
 
	x=x0;
	y=y0;
 
	p=2*dy-dx;
 
    
    if (dx == 0 ) { //Garis Horizontal
        while (y < y1) {
            fillPixel(x, y, r, g, b, t);
            y++;
        }
    } else if (dy == 0) { //Garis Vertical
        while (x < x1) {
            fillPixel(x, y, r, g, b, t);
            x++;
        }
        
    } else if (dy/dx < 0) { //Gradien Negatif
    
        dx=abs(x1-x);
	    dy=abs(y1-y);
        p = 2*dy - dx;

        for (i = 1; i <= dx; i++) {
            fillPixel(x, y ,r, g, b, t);
            while (p > 0) {
                y = y - 1;
                p = p - 2*dx;
            }
            x = x + 1;
            p = p + 2*dy;
        }

    } else if (dy/dx > 0) { //Gradien Positif

        while(x<x1)
        {
            if(p>=0)
            {
                fillPixel(x, y, r, g, b, t);
                y=y+1;
                p=p+2*dy-2*dx;
            }
            else
            {
                fillPixel(x, y, r, g, b, t);
                p=p+2*dy;
            }
            x=x+1;
        }    
    } 

	
}

void clearBackground() {
    for(int a=0; a<700;a++){
        for(int b=0; b<1300;b++){
            fillPixel(b, a, 0, 0, 0, 0);
        }
    }
}

// void printLingkaran(int x, int y, int r)
// {
//     int i, x1, y1;
//     for (i = 0; i <= 720; i++)
//     {
//         x1 = (int) x + nearbyint(r * cos(i * PI / 360));
//         y1 = (int) y + nearbyint(r * sin(i * PI / 360));

//         fillPixel(x1, y1, 255, 255, 0, 0);
//     }
// }

// void printMatahari(int x, int y, int r, int d){
//     //lingkaran
//     int i;
//     int x1, x2, y1, y2;

//     printLingkaran(x, y, r);

//     /*
//     i = 0;

//     x1 = (int) x + nearbyint(r * cos(i * PI / 180));
//     y1 = (int) y + nearbyint(r * sin(i * PI / 180));
//     for (i = 60; i<=360; i+=60)
//     {
//         x2 = (int) x + nearbyint(r * cos(i * PI / 180));
//         y2 = (int) y + nearbyint(r * sin(i * PI / 180));

//         printGaris(x1, y1, x2, y2, 255, 255, 255 ,0);

//         x1 = x2;
//         y1 = y2;
//     } */



//     //garis kecil
    
//     for (i = 0; i<=360; i += 15)
//     {
//         x1 = (int) x + nearbyint(r * cos(i * PI / 180));
//         x2 = (int) x + nearbyint((r + d) * cos(i * PI / 180));
//         y1 = (int) y + nearbyint(r * sin(i * PI / 180));
//         y2 = (int) y + nearbyint((r + d) * sin(i * PI / 180));

//         if (x1 < x2)
//         {
//             printGaris(x1, y1, x2, y2, 255, 255, 0, 0);
//         }
//         else
//         {
//             printGaris(x2, y2, x1, y1, 255, 255, 0, 0);
//         }
//     }
// }

// void printSawahL(int x0, int y0, int n, int r){
// //(x0, y0) titik awal sawah
// //n menyatakan banyak garis, r menyatakan jarak antara 2 garis
// 	int x1 = (n)*r+x0;
// 	int y1 = (n)*r+y0;
//     for (int i=0;i<n;i++){
//         printGaris(x0, y0, x1, y0, 127, 247, 29, 0);
//         y0+=r;
//     }
//     for (int i=0;i<n;i++){
//         printGaris(x0+r, y0, x0, y1, 127, 247, 29, 0);
//         x0+=r;
//     } 
//  }

// void printSawahR(int x0, int y0, int n, int r){
// //(x0, y0) titik awal sawah
// //n menyatakan banyak garis, r menyatakan jarak antara 2 garis
// 	int x1 = (n)*r+x0;
// 	int y1 = (n)*r+y0;
//     for (int i=0;i<n;i++){
//         printGaris(x0, y0, x1, y0, 127, 247, 29, 0);
//         y0+=r;
//     }
//     for (int i=0;i<n;i++){
//         printGaris(x0, y0, x0+r, y1, 127, 247, 29, 0);
//         x0+=r;
//     } 
//  }

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
    
    printNama("dandy", 40,40,150,50,50,0);
    printNama("hafizh", 40,110,150,250,50,10);
    printNama("william", 40,180,150,150,50,100);
    printNama("ivan", 40,250,150,100,40,20);
    printNama("yogi", 40,320,150,200,40,20);
    printNama("judhis", 40,390,150,120,40,20);
    // Positif
    printGaris(40, 40, 200, 200, 255, 255, 255, 0);
    printGaris(40, 40, 40, 200, 255, 255, 255, 0);
    printGaris(40, 200, 200, 200, 255, 255, 255, 0);
    // Negatif
    printGaris(40, 400, 200, 240, 255, 255, 255, 0);
    printGaris(40, 240, 40, 400, 255, 255, 255, 0);
    printGaris(40, 240, 200, 240, 255, 255, 255, 0);
    
    // Gunung
    // printGaris(40, 400, 360, 80, 0, 102, 204, 0);
    // printGaris(360, 80, 680, 400, 0, 102, 204, 0);
    // printGaris(640, 360, 920, 80, 0, 102, 204, 0);
    // printGaris(920, 80, 1240, 400, 0, 102, 204, 0);

    // //Jalan
    // printGaris(530,400,810,700,153,76,0,0);
    // printGaris(670,400,950,700,153,76,0,0);

    // //Matahari
    // printMatahari(650, 175, 80, 15);
	
	//sawah
	// printSawahL(120, 450, 5, 50);
	// printGaris(120, 700, 170, 450, 127, 247, 29, 0);
	// printGaris(170, 700, 220, 450, 127, 247, 29, 0);
	// printGaris(220, 700, 270, 450, 127, 247, 29, 0);
	// printGaris(270, 700, 320, 450, 127, 247, 29, 0);
	// printGaris(320, 700, 370, 450, 127, 247, 29, 0);

    // printSawahR(1020, 450, 5, 50);
	// printGaris(1020, 700, 1070, 450, 127, 247, 29, 0);
	// printGaris(1070, 700, 1120, 450, 127, 247, 29, 0);
	// printGaris(1120, 700, 1170, 450, 127, 247, 29, 0);
	// printGaris(1170, 700, 1220, 450, 127, 247, 29, 0);
	// printGaris(1220, 700, 1270, 450, 127, 247, 29, 0);
    /*
    printSawahL(960, 450, 5, 50);
	//printSawahR(960, 450, 5, 50);
	printGaris(1010, 700, 960, 450, 127, 247, 29, 0);
	printGaris(1060, 700, 1010, 450, 127, 247, 29, 0);
	printGaris(1110, 700, 1060, 450, 127, 247, 29, 0);
	printGaris(1160, 700, 1110, 450, 127, 247, 29, 0);
    location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                        (y+vinfo.yoffset) * finfo.line_length;
            
	printGaris(1210, 700, 1160, 450, 127, 247, 29, 0);
    */


	
    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}