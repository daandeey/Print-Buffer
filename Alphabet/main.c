#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>

#include "alphabet.c"

//Struct new element named Element
typedef struct Element {
     char name[50];
     int x_in;
     int y_in;
     int r;
     int g;
     int b;
     int t;
} Element;

void scanFile(const char filename[25] , Element elem[100], int *idx){
    FILE *payfile;
    int i = 0;

    payfile = fopen(filename,"r");
    if(!payfile){
    	printf("Tidak ada file\n");
    } else {
	    while(EOF!=fscanf(payfile,"%s %d %d %d %d %d %d",
	            elem[i].name,
                &elem[i].x_in,
                &elem[i].y_in,
                &elem[i].r,
                &elem[i].g,
                &elem[i].b,
                &elem[i].t
                )
            ) 
	    {
	        i++;
	    }
	    *idx = i;
	    fclose(payfile);
	}
}

int main(){
    Element elem[50];
    int x = 0, y = 0;
    long int location = 0;
    int num = 0;

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

    scanFile("input.txt", elem, &num);
    for(int i = 0; i < num; i++)
    {
        printNama(elem[i].name, elem[i].x_in, elem[i].y_in, elem[i].r, elem[i].g, elem[i].b, elem[i].t);
    }
    
    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}