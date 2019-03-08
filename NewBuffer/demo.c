#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>
#include <string.h>
#include "animation.c"
typedef struct Element {
     char name[10], type;
     float x[12];
 
} Element;

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

void runAnimation(Element war[100], int i){
    for(int j=0; j<i; j++){
        printf("%s\n", war[j].name);
        if(strcmp(war[j].name,"Bangunan") == 0){
            //printf("yes\n");
            if (strcmp(war[j].type,"S") == 0){
                perbesarBangunan(war[i].x[1], war[i].x[2], war[i].x[3], war[i].x[4], war[i].x[5], 
                war[i].x[6], war[i].x[7], war[i].x[8], war[i].x[9]);
            }
        } else if(strcmp(war[j].name,"Matahari") == 0){
            //printf("yes\n");
            if (strcmp(war[j].type,"R") == 0){
                putarMatahari(war[i].x[1], war[i].x[2], war[i].x[3], 
            war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
            war[i].x[9], war[i].x[10], war[i].x[11], war[i].x[12]);
            }
        } else if(strcmp(war[j].name,"Awan") == 0){
            //printf("yes\n");
            if (strcmp(war[j].type,"T") == 0){
                geserAwan(war[i].x[1], war[i].x[2], war[i].x[3], 
            war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
            war[i].x[9], war[i].x[10], war[i].x[11]);
            }
        } else if(strcmp(war[j].name,"Tank") == 0){
            //printf("yes\n");
            if (strcmp(war[j].type,"T") == 0){
                geserTank(war[i].x[1], war[i].x[2], war[i].x[3], 
            war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
            war[i].x[9], war[i].x[10]);
            }
        } else if(strcmp(war[j].name,"Bullet") == 0){
            //printf("yes\n");
            if (strcmp(war[j].type,"T") == 0){
                geserBullet(war[i].x[1], war[i].x[2], war[i].x[3], 
            war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
            war[i].x[9], war[i].x[10], war[i].x[11]);
            }
        } else if(strcmp(war[j].name,"Pesawat") == 0){
            //printf("yes\n");
            if (strcmp(war[j].type,"T") == 0){
               geserPesawat(war[i].x[1], war[i].x[2], war[i].x[3], 
            war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
            war[i].x[9], war[i].x[10]);
            }
        } else if(strcmp(war[j].name,"Rudal") == 0){
            //printf("yes\n");
            if (strcmp(war[j].type,"T") == 0){
                geserRudal(war[i].x[1], war[i].x[2], war[i].x[3], 
            war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
            war[i].x[9], war[i].x[10], war[i].x[11]);
            }
        }
        
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

    // Begin Draw

    // printSegitiga(100, 100, 150, 175, 250, 400, 255, 255, 255, 0);
    // printPersegiPanjang(75, 30, 125, 55, 255, 255, 255, 0);
    // printPersegiPanjang(125, 40, 175, 45, 255, 255, 255, 0);
    // printPoligon(100, 100, 6, 50, 30, 255, 255, 255, 0);
    // printPersegi(100, 100, 500, 255, 255, 255, 0);

    /*
    printTank(400, 500, 25, 0, 100, 0, 0);
    printBullet(500, 470, 5, 4, 143, 188, 143, 0);
    printBangunan(625, 285, 0.875, 255, 141, 53, 0);
    printAwan(750, 200, 50, 25, 255, 255, 255, 0);
    printAwan(950, 150, 50, 25, 255, 255, 255, 0);
    printPesawat(475, 160, 0.75, 0, 0, 139, 0);
    printRudal(400, 225, 1, 3, 95, 158, 160, 0);
    */

    // geserPoligon(300, 300, 5, 100, 100, 0, 255, 255, 255, 0, 200, 100, 1);
/*
    perbesarBangunan(625, 285, 0.500, 255, 141, 53, 0, 1.75, 1);
    putarMatahari(750, 100, 10, 50, 50, 0, 255, 255, 0, 0, 100, 1);
    geserAwan(750, 225, 50, 25, 255, 255, 255, 0, 25, 0, 1);
    geserAwan(950, 175, 50, 25, 255, 255, 255, 0, 25, 0, 1);
    geserTank(300, 500, 25, 0, 100, 0, 0, 100, 0, 1);
    geserBullet(500, 470, 5, 3, 143, 188, 143, 0, 50, 0, 1);
    geserPesawat(400, 160, 0.75, 0, 0, 139, 0, 75, 0, 1);
    geserRudal(400, 225, 1, 3, 95, 158, 160, 0, 0, 100, 1);
*/

    FILE *payfile;
    Element war[100];
    int j = 0, num;

    payfile = fopen("input.txt","r");
    while(EOF!=fscanf(payfile,"%9s %c %f %f %f %f %f %f %f %f %f %f %f %f",
            war[j].name ,&war[j].type, &war[j].x[1], &war[j].x[2], &war[j].x[3], 
            &war[j].x[4], &war[j].x[5], &war[j].x[6], &war[j].x[7], &war[j].x[8],
            &war[j].x[9], &war[j].x[10], &war[j].x[11], &war[j].x[12])) 
        {
           // printf("%s \n", war[j].name);
            j++;
        }
    clearBackground();
    for(int i=0; i<j; i++){
      // printf("%d\n", i);
        if(strcmp(war[i].name,"Bangunan") == 0){
            //printf("yes\n");
            //printf("%c\n", war[j].type);
            if (war[i].type=='S'){
                perbesarBangunan(war[i].x[1], war[i].x[2], war[i].x[3], war[i].x[4], war[i].x[5], 
                war[i].x[6], war[i].x[7], war[i].x[8], war[i].x[9]);
            }
        } else if(strcmp(war[i].name,"Matahari") == 0){
            //printf("yes\n");
            if ((war[i].type=='R')){
               // printf("yes\n");
                putarMatahari(750, 100, 10, 50, 50, 0, 255, 255, 0, 0, 100, 1);
            //     putarMatahari((int)war[i].x[1], (int)war[i].x[2], (int)war[i].x[3], 
            // (int)war[i].x[4], (int)war[i].x[5], (int)war[i].x[6], (int)war[i].x[7], (int)war[i].x[8],
            // (int)war[i].x[9], (int)war[i].x[10], (int)war[i].x[11], (int)war[i].x[12]);
            }
        } else if(strcmp(war[i].name,"Awan") == 0){
            //printf("yes\n");
            if ((war[i].type=='T')){
                geserAwan(war[i].x[1], war[i].x[2], war[i].x[3], 
            war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
            war[i].x[9], war[i].x[10], war[i].x[11]);
            }
        } else if(strcmp(war[i].name,"Tank") == 0){
            //printf("yes\n");
            if (war[i].type=='T'){
                geserTank(war[i].x[1], war[i].x[2], war[i].x[3], 
            war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
            war[i].x[9], war[i].x[10]);
            }
        } else if(strcmp(war[i].name,"Bullet") == 0){
            //printf("yes\n");
            if (war[i].type=='T'){
                geserBullet(war[i].x[1], war[i].x[2], war[i].x[3], 
            war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
            war[i].x[9], war[i].x[10], war[i].x[11]);
            }
        } else if(strcmp(war[i].name,"Pesawat") == 0){
            //printf("yes\n");
            if (war[i].type=='T'){
               geserPesawat(war[i].x[1], war[i].x[2], war[i].x[3], 
            war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
            war[i].x[9], war[i].x[10]);
            }
        } else if(strcmp(war[i].name,"Rudal") == 0){
            //printf("yes\n");
            if (war[i].type=='T'){
                geserRudal(war[i].x[1], war[i].x[2], war[i].x[3], 
            war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
            war[i].x[9], war[i].x[10], war[i].x[11]);
            }
        }
        
    }
    
    //runAnimation(&war[100], i);

    // End Draw

    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}