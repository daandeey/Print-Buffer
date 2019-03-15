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

//Struct new element named Element
typedef struct Element {
     char name[10], type;
     float x[12];
 
} Element;

// Read file named namaFile and copy the parameters in file to "war"
void scanFile(const char namaFile[25] , Element war[100], int *idx){
    FILE *payfile;
    int i = 0;

    payfile = fopen(namaFile,"r");
    if(!payfile){
    	printf("Tidak ada file\n");
    } else {
	    while(EOF!=fscanf(payfile,"%9s %c %f %f %f %f %f %f %f %f %f %f %f %f",
	            war[i].name ,&war[i].type, &war[i].x[1], &war[i].x[2], &war[i].x[3], 
	            &war[i].x[4], &war[i].x[5], &war[i].x[6], &war[i].x[7], &war[i].x[8],
	            &war[i].x[9], &war[i].x[10], &war[i].x[11], &war[i].x[12])) 
	    {
	        i++;
	    }
	    *idx = i;
	    fclose(payfile);
	}
}

//Run all animation in array "war" with size of command = j
void runAnimation(Element war[100], int j){

    //Iteration until do all the command in file 
    for(int i=0; i<j; i++){
        //If command i is Bangunan
        //Do Dilation if type = S
        if(strcmp(war[i].name,"Bangunan") == 0){
            if (war[i].type=='S'){
                perbesarBangunan(war[i].x[1], war[i].x[2], war[i].x[3], war[i].x[4], war[i].x[5], 
                    war[i].x[6], war[i].x[7], war[i].x[8], war[i].x[9]);
            }
        } 

        //If command i is Matahari
        //Do Rotation if type = R
        else if(strcmp(war[i].name,"Matahari") == 0){
            if ((war[i].type=='R')){
                putarMatahari(750, 100, 10, 50, 50, 0, 255, 255, 0, 0, 100, 1);
            }
        } 

        //If command i is Tank
        //Do Translation if type = T
        else if(strcmp(war[i].name,"Tank") == 0){
            if (war[i].type=='T'){
                geserTank(war[i].x[1], war[i].x[2], war[i].x[3], 
                    war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
                    war[i].x[9], war[i].x[10]);
            }
        } 

        //If command i is Bullet
        //Do Translation if type = T
        else if(strcmp(war[i].name,"Bullet") == 0){
            if (war[i].type=='T'){
                geserBullet(war[i].x[1], war[i].x[2], war[i].x[3], 
                    war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
                    war[i].x[9], war[i].x[10], war[i].x[11]);
            }
        } 

        //If command i is Pesawat
        //Do Translation if type = T
        else if(strcmp(war[i].name,"Pesawat") == 0){
            if (war[i].type=='T'){
               geserPesawat(war[i].x[1], war[i].x[2], war[i].x[3], 
                    war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
                    war[i].x[9], war[i].x[10]);
            }
        } 

        //If command i is Rudal
        //Do Translation if type = T
        else if(strcmp(war[i].name,"Rudal") == 0){
            if (war[i].type=='T'){
                geserRudal(war[i].x[1], war[i].x[2], war[i].x[3], 
                    war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
                    war[i].x[9], war[i].x[10], war[i].x[11]);
            }
        }
        
    }
}

void startDraw(){
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
}

void endDraw(){
    // End Draw
    munmap(fbp, screensize);
    close(fbfd);
}

int main(){
    //Local Variable
    Element war[100];
    int num;

    //Variable Initiation
    num = 0;

    //Start a draw
    startDraw();

    //Do a scan file
    scanFile("input.txt",war,&num);

    //Clear Background
    clearBackground();

    //Run the animation
    runAnimation(war,num);

    endDraw();
    return 0;
}