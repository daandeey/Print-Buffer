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
#include "garis.h"


#define PI 3.14159265
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


void clearBackground() {
    for(int a=0; a<700;a++){
        for(int b=0; b<1300;b++){
            fillPixel(b, a, 0, 0, 0, 0);
        }
    }
}


// Read file named namaFile and copy the parameters in file to "war"
// void scanFile(const char namaFile[25] , Element view[100], int *idx){
//     FILE *payfile;
//     int i = 0;

//     payfile = fopen(namaFile,"r");
//     if(!payfile){
//     	printf("Tidak ada file\n");
//     } else {
// 	    while(EOF!=fscanf(payfile,"%c %f %f %f %f %f %f %f %f",
// 	            view[i].name , &view[i].x[1], &view[i].x[2], &view[i].x[3], 
// 	            &view[i].x[4], &view[i].x[5], &view[i].x[6], &view[i].x[7], &view[i].x[8])) 
// 	    {
// 	        i++;
// 	    }
// 	    *idx = i;
// 	    fclose(payfile);
// 	}
// }

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
    
    //Gunung
    printGunung(50, 50);

    //Jalan
    printJalan(50, 50);

    //Matahari
    printMatahari(300, 108, 27, 15);

	//sawah
    printSawah(50, 50, 50);

    //awan
    printAwan(559, 86, 26, 26, 255 ,255 ,255 ,0);
	
    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}
