#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>
#include "shape.c"
typedef struct Element {
     char name[10], type;
     float x[12];
 
} Element;

// Defining region codes 
int INSIDE = 0; // 0000 
int LEFT = 1;   // 0001 
int RIGHT = 2;  // 0010 
int BOTTOM = 4; // 0100 
int TOP = 8;    // 1000 

// Defining x_max, y_max and x_min, y_min for 
// clipping rectangle. Since diagonal points are 
// enough to define a rectangle 
const int x_max = 100; 
const int y_max = 80; 
const int x_min = 40; 
const int y_min = 40; 

void readFile(FILE *payfile, Element war[100], int *idx, int i){
 while(EOF!=fscanf(payfile,"%9s %c %f %f %f %f %f %f %f %f %f %f %f %f",
            war[i].name ,&war[i].type, &war[i].x[1], &war[i].x[2], &war[i].x[3], 
            &war[i].x[4], &war[i].x[5], &war[i].x[6], &war[i].x[7], &war[i].x[8],
            &war[i].x[9], &war[i].x[10], &war[i].x[11], &war[i].x[12])) 
        {
            i++;
        }
    *idx = i;
}

int getRegionCode(int x, int y) { 
    int code = 0; // 0000

    if (x < x_min) code |= 1; // 0001
    else if (x > x_max) code |= 2; // 0010

    if (y < y_min) code |= 4; // 0100
    else if (y > y_max) code |= 8; // 1000

    return code; 
} 

void clip(int x1, int y1, int x2, int y2, int r, int g, int b, int t) {
    if (x1 >= vinfo.xres || y1 >= vinfo.yres || x1 < 0 || y1 < 0) return;
    if (x2 >= vinfo.xres || y2 >= vinfo.yres || x2 < 0 || y2 < 0) return;

    int code1 = getRegionCode(x1, y1); 
    int code2 = getRegionCode(x2, y2); 

    int accept = 0; 

    while (1) { 
        if ((code1 == 0) && (code2 == 0)) { 
            // If both endpoints lie within rectangle 
            accept = 1; 
            break; 
        } 
        else if (code1 & code2) { 
            // If both endpoints are outside rectangle, 
            // in same region 
            break; 
        } else { 
            // Some segment of line lies within the 
            // rectangle 
            int code_out; 
            double x, y; 

            // At least one endpoint is outside the  
            // rectangle, pick it. 
            if (code1 != 0) 
                code_out = code1; 
            else
                code_out = code2; 

            // Find intersection point; 
            // using formulas y = y1 + slope * (x - x1), 
            // x = x1 + (1 / slope) * (y - y1) 
            if (code_out & TOP) { 
                // point is above the clip rectangle 
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1); 
                y = y_max; 
            } 
            else if (code_out & BOTTOM) { 
                // point is below the rectangle 
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1); 
                y = y_min; 
            } 
            else if (code_out & RIGHT) { 
                // point is to the right of rectangle 
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1); 
                x = x_max; 
            } 
            else if (code_out & LEFT) { 
                // point is to the left of rectangle 
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1); 
                x = x_min; 
            } 

            // Now intersection point x,y is found 
            // We replace point outside rectangle 
            // by intersection point 
            if (code_out == code1) { 
                x1 = x; 
                y1 = y; 
                code1 = getRegionCode(x1, y1); 
            } else { 
                x2 = x; 
                y2 = y; 
                code2 = getRegionCode(x2, y2); 
            } 
        } 
    } 
    if (accept) { 
        printGaris(x1, y1, x2, y2, r, g, b, t);
    }
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
    if ((long)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    printf("The framebuffer device was mapped to memory successfully.\n");

    clearBackground();


    // create frame
    /*
    printGaris(40,40,100,40,255,255,255,0);
    printGaris(40,40,40,80,255,255,255,0);
    printGaris(100,40,100,80,255,255,255,0);
    printGaris(40,80,100,80,255,255,255,0);
    
    clip(10, 30, 50, 60, 255, 255, 255, 0);
    clip(70, 70, 110, 60, 255, 255, 255, 0);
    */

   printPoligon(300, 300, 5, 50, 50, 0, 255, 255, 255, 0);
   floodFillPixel(300, 300, 0, 0, 0, 0, 255, 255, 255, 0);

   fillBulanSabit(500, 500, 90, 255, 255, 255, 0);

    // End Draw

    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}