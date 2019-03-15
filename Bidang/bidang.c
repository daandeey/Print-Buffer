#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>
#include "shape.c"

//Struct new element named Element
typedef struct Element {
     char name[10];
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
	    while(EOF!=fscanf(payfile,"%9s %f %f %f %f %f %f %f %f %f %f %f %f",
	            war[i].name , &war[i].x[1], &war[i].x[2], &war[i].x[3], 
	            &war[i].x[4], &war[i].x[5], &war[i].x[6], &war[i].x[7], &war[i].x[8],
	            &war[i].x[9], &war[i].x[10], &war[i].x[11], &war[i].x[12])) 
	    {
	        i++;
	    }
	    *idx = i;
	    fclose(payfile);
	}
}

//Print all "bidang" in array "war" with size of command = j
void printBidang(Element war[100], int j){

    //Iteration until do all the command in file 
    for(int i=0; i<j; i++){
        //If command i is Bangunan
        if(strcmp(war[i].name,"Bangunan") == 0){
            printBangunan(war[i].x[1], war[i].x[2], war[i].x[3], 
                    war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7]);
        } 

        //If command i is Matahari
        else if(strcmp(war[i].name,"Matahari") == 0){
            printMatahari(war[i].x[1], war[i].x[2], war[i].x[3], 
                    war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8],
                    war[i].x[9], war[i].x[10]);
        } 

        //If command i is Awan
        else if(strcmp(war[i].name,"Awan") == 0){
            printAwan(war[i].x[1], war[i].x[2], war[i].x[3], 
                    war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8]);
        } 

        //If command i is Tank
        else if(strcmp(war[i].name,"Tank") == 0){
            printTank(war[i].x[1], war[i].x[2], war[i].x[3], 
                    war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7]);
        } 

        //If command i is Bullet
        else if(strcmp(war[i].name,"Bullet") == 0){
            printBullet(war[i].x[1], war[i].x[2], war[i].x[3], 
                    war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7],war[i].x[8]);
        } 

        //If command i is Pesawat
        else if(strcmp(war[i].name,"Pesawat") == 0){
            printPesawat(war[i].x[1], war[i].x[2], war[i].x[3], 
                    war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7]);
        } 

        //If command i is Rudal
        else if(strcmp(war[i].name,"Rudal") == 0){
            printRudal(war[i].x[1], war[i].x[2], war[i].x[3], 
                    war[i].x[4], war[i].x[5], war[i].x[6], war[i].x[7], war[i].x[8]);
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
	//initiating variable
	Element war[100];
    int num;

    //scan file eksternal
	scanFile("input.txt",war,&num);
	
	//start gambar
	startDraw();

	//bersihkan background
	clearBackground();

	//mencetak bidang pada layar
	printBidang(war,num);

	//selesai menggambar
	endDraw();
	
	return 0;
}