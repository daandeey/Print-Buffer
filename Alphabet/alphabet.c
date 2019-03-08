#include "alphabet.h"

#define PI 3.14159265
#define THICK 6
#define SIZE 60
#define for_each_item(item, list) \
    for(T * item = list->head; item != NULL; item = item->next)


void printA(int x_in, int y_in, int r, int g, int b, int t){
    int x, y;
    //Garis kiri ke bawah
    for(x = x_in; x < x_in + THICK; x++){
        for(y = y_in; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis atas ke kanan
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in; y < y_in + THICK; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kanan ke bawah
    for(x = x_in + SIZE/2 - THICK; x < x_in + SIZE/2; x++){
        for(y = y_in; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis bawah ke kanan
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in + SIZE/2 - THICK; y < y_in + SIZE/2; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
}

void printB(int x_in, int y_in, int r, int g, int b, int t){
    int x,y,z,x1,x2,y1,y2;
    initFbp();
    for(z=0;z<5;z++){
	if (z == 0) { //Garis horizontal atas
	    x1 = x_in; x2 = x_in+SIZE/2-THICK; y1 = y_in; y2 = y_in+THICK;
	} else if (z == 1) { //Garis vertikal kiri
	    x1 = x_in; x2 = x_in+THICK; y1 = y_in; y2 = y_in+SIZE;
	} else if (z == 2) { //Garis horizontal tengah
	    x1 = x_in; x2 = x_in+SIZE/2-THICK; y1 = y_in+SIZE/2-THICK/2; y2 = y_in+SIZE/2+THICK/2;
	} else if (z == 3) { //Garis vertikal kanan
	    x1 = x_in-THICK+SIZE/2; x2 = x_in+SIZE/2; y1 = y_in+THICK; y2 = y_in+SIZE-THICK;
	} else if (z == 4) { //Garis horizontal bawah
	    x1 = x_in; x2 = x_in+SIZE/2-THICK; y1 = y_in+SIZE-THICK; y2 = y_in+SIZE;
	}
        for(y=y1;y<y2;y++){
            for(x=x1;x<x2;x++){
                fillPixel(x, y, r, g, b, t);
            }
        }
    }
}

void printC(int x_in, int y_in, int r, int g, int b, int t){
    int x,y;
    initFbp();
    //Garis ke bawah
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis ke kanan, paling atas
    for(y=y_in;y<y_in+THICK;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis ke kanan, bagian bawah
    for(y=y_in+SIZE-THICK;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
}

void printD(int x_in, int y_in, int r, int g, int b, int t){
    int x, y;
    //Garis kiri + 1
    for(y = y_in; y < y_in + SIZE; y++){
        for(x = x_in + THICK; x < x_in + 2*THICK; x++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    //Garis atas 
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in; y < y_in + THICK; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    //Garis bawah 
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in + SIZE - THICK; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kanan
    for(x = x_in + SIZE/2 - THICK; x < x_in + SIZE/2; x++){
        for(y = y_in + THICK; y < y_in + SIZE - THICK; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
}

void printE(int x_in, int y_in, int r, int g, int b, int t){
    int x,y;
    initFbp();
    //Garis ke bawah
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis ke kanan, paling atas
    for(y=y_in;y<y_in+THICK;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis ke kanan, bagian tengah
    for(y=y_in+SIZE/2-THICK/2;y<y_in+SIZE/2+THICK/2;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis ke kanan, bagian bawah
    for(y=y_in+SIZE-THICK;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }

}

void printF(int x_in, int y_in, int r, int g, int b, int t){
    int x,y,z,x1,x2,y1,y2;
    initFbp();
    //Garis ke bawah
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis horizontal paling atas
    for(y=y_in;y<y_in+THICK;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);  
        }
    }
    //Garis hortizontal bagian tengah
    for(y=y_in+SIZE/2-THICK/2;y<y_in+SIZE/2+THICK/2;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
}

void printG(int x_in, int y_in, int r, int g, int b, int t){
    int x, y;
    //Garis kiri ke bawah
    for(x = x_in; x < x_in + THICK; x++){
        for(y = y_in; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis atas ke kanan
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in; y < y_in + THICK; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis tengah ke kanan
    for(x = x_in + SIZE/4; x < x_in + SIZE/2; x++){
        for(y = y_in + SIZE/2 - THICK/2; y < y_in + SIZE/2 + THICK/2; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kanan ke bawah
    for(x = x_in + SIZE/2 - THICK; x < x_in + SIZE/2; x++){
        for(y = y_in + SIZE/2; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis bawah ke kanan
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in + SIZE - THICK; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
}

void printH(int x_in, int y_in, int r, int g, int b, int t){
    int x,y,z,x1,x2,y1,y2;
    initFbp();
    for(z=0;z<3;z++){
	if (z == 0) { //Garis vertikal kiri
	    x1 = x_in; x2 = x_in+THICK; y1 = y_in; y2 = y_in+SIZE;
	} else if (z == 1) { //Garis horizontal tengah
	    x1 = x_in; x2 = x_in+SIZE/2; y1 = y_in+SIZE/2-THICK/2; y2 = y_in+SIZE/2+THICK/2;
	} else if (z == 2) { //Garis vertikal kanan
	    x1 = x_in+SIZE/2-THICK; x2 = x_in+SIZE/2; y1 = y_in; y2 = y_in+SIZE;
	}
        for(y=y1;y<y2;y++){
            for(x=x1;x<x2;x++){
                fillPixel(x, y, r, g, b, t);
            }
        }
    }
}

void printI(int x_in, int y_in, int r, int g, int b, int t){
    int x,y;
    initFbp();
    //Garis ke bawah
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
}

void printJ(int x_in, int y_in, int r, int g, int b, int t){
    int x, y;
    //Garis Tengah ke bawah
    for(x = x_in + SIZE/4; x < x_in + SIZE/4 + THICK; x++){
        for(y = y_in; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    //Garis atas ke kanan
    for(x = x_in + SIZE/4 - THICK; x < x_in + SIZE/4 + 2*THICK; x++){
        for(y = y_in; y < y_in + THICK; y++){
            fillPixel(x, y, r, g, b ,t);
        }
    }
    //Garis bawah ke kanan
    for(x = x_in; x < x_in + SIZE/4 + THICK; x++){
        for(y = y_in + SIZE - THICK; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    //Garis kiri ke atas
    for(x = x_in; x < x_in + THICK; x++){
        for(y = y_in + SIZE - 3*THICK; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
}

void printK(int x_in, int y_in, int r, int g, int b, int t){
    int x, y;
    //Garis kiri ke bawah
    for(x = x_in; x < x_in + THICK; x++){
        for(y = y_in; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis tengah1 ke atas
    for(x = x_in + SIZE/4 - THICK; x < x_in + SIZE/4; x++){
        for(y = y_in + SIZE/3; y < y_in + SIZE/2; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis tengah2 ke atas
    for(x = x_in + SIZE/3 - THICK; x < x_in + SIZE/3; x++){
        for(y = y_in + SIZE/6; y < y_in + SIZE/3; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis tengah3 ke atas
    for(x = x_in + SIZE*2/5 - THICK; x < x_in + SIZE*2/5; x++){
        for(y = y_in; y < y_in + SIZE/6; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis tengah1 ke bawah
    for(x = x_in + SIZE/4 - THICK; x < x_in + SIZE/4; x++){
        for(y = y_in + SIZE/2; y < y_in + SIZE*2/3; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis tengah2 ke bawah
    for(x = x_in + SIZE/3 - THICK; x < x_in + SIZE/3; x++){
        for(y = y_in + SIZE*2/3; y < y_in + SIZE*5/6; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis tengah3 ke bawah
    for(x = x_in + SIZE*2/5 - THICK; x < x_in + SIZE*2/5; x++){
        for(y = y_in + SIZE*5/6; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
}

void printL(int x_in, int y_in, int r, int g, int b, int t){
    int x,y;
    initFbp();
    //Garis ke bawah
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis ke kanan
    for(y=y_in+SIZE-THICK;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);  
        }
    }
}

void printM(int x_in, int y_in, int r, int g, int b, int t){
    int x,y,z,x1,x2,y1,y2;
    initFbp();
    //Garis ke bawah
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis ke bawah bagian kanan
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in+SIZE/2-THICK;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis Miring ujung kiri atas ke ujung kanan bawah
    for(y=y_in+2*SIZE/10;y<y_in+4*SIZE/10;y++){
        for(x=x_in+THICK;x<x_in+2*THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    for(y=y_in+4*SIZE/10;y<y_in+6*SIZE/10;y++){
        for(x=x_in+2*THICK;x<x_in+3*THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    for(y=y_in+2*SIZE/10;y<y_in+4*SIZE/10;y++){
        for(x=x_in+3*THICK;x<x_in+4*THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
}

void printN(int x_in, int y_in, int r, int g, int b, int t){
    int x,y,z,x1,x2,y1,y2;
    initFbp();
    //Garis ke bawah
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis ke bawah bagian kanan
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in+SIZE/2-THICK;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis Miring ujung kiri atas ke ujung kanan bawah
    for(y=y_in+2*SIZE/10;y<y_in+4*SIZE/10;y++){
        for(x=x_in+THICK;x<x_in+2*THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    for(y=y_in+4*SIZE/10;y<y_in+6*SIZE/10;y++){
        for(x=x_in+2*THICK;x<x_in+3*THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    for(y=y_in+6*SIZE/10;y<y_in+8*SIZE/10;y++){
        for(x=x_in+3*THICK;x<x_in+4*THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
}

void printO(int x_in, int y_in, int r, int g, int b, int t){
    int x, y;
    //Garis kiri ke bawah
    for(x = x_in; x < x_in + THICK; x++){
        for(y = y_in; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis atas ke kanan
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in; y < y_in + THICK; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kanan ke bawah
    for(x = x_in + SIZE/2 - THICK; x < x_in + SIZE/2; x++){
        for(y = y_in; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis bawah ke kanan
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in + SIZE - THICK; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
}

void printP(int x_in, int y_in, int r, int g, int b, int t){
    int x,y;
    initFbp();
    //Garis ke bawah bagian kiri
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+THICK;x++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    //Garis ke kanan bagian atas
    for(y=y_in;y<y_in+THICK;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis ke bawah bagian kanan
    for(y=y_in;y<y_in+SIZE/2;y++){
        for(x=x_in+SIZE/2-THICK;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis ke kanan bagian bawah
    for(y=y_in+SIZE/2-THICK;y<y_in+SIZE/2;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    } 
}

void printQ(int x_in, int y_in, int r, int g, int b, int t){
    int x,y,z,x1,x2,y1,y2;
    initFbp();
    for(z=0;z<6;z++){
	if (z == 0) { //Garis vertikal kiri
	    x1 = x_in; x2 = x_in+THICK; y1 = y_in+THICK; y2 = y_in+SIZE-THICK;
	} else if (z == 1) { //Garis horizontal atas
	    x1 = x_in+THICK; x2 = x_in+SIZE/2-THICK; y1 = y_in; y2 = y_in+THICK;
	} else if (z == 2) { //Garis vertikal kanan
	    x1 = x_in+SIZE/2-THICK; x2 = x_in+SIZE/2; y1 = y_in+THICK; y2 = y_in+SIZE-THICK;
	} else if (z == 3) { //Garis miring 1
	    x1 = x_in+SIZE/2-2*THICK; x2 = x_in+SIZE/2-THICK; y1 = y_in+SIZE-2*THICK; y2 = y_in+SIZE-THICK;
	} else if (z == 4) { //Garis miring 2
	    x1 = x_in+SIZE/2; x2 = x_in+SIZE/2+THICK; y1 = y_in+SIZE; y2 = y_in+SIZE+THICK;
	} else if (z == 5) { //Garis horizontal bawah
	    x1 = x_in+THICK; x2 = x_in+SIZE/2; y1 = y_in+SIZE-THICK; y2 = y_in+SIZE;
	}
        for(y=y1;y<y2;y++){
            for(x=x1;x<x2;x++){
                fillPixel(x, y, r, g, b, t);
            }
        }
    }
}

void printR(int x_in, int y_in, int r, int g, int b, int t){
    int x, y;
    //Garis kiri ke bawah
    for(x = x_in; x < x_in + THICK; x++){
        for(y = y_in; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis atas ke kanan
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in; y < y_in + THICK; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kanan ke bawah
    for(x = x_in + SIZE/2 - THICK; x < x_in + SIZE/2; x++){
        for(y = y_in; y < y_in + SIZE/2; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis tengah1 ke bawah
    for(x = x_in + SIZE/4 - THICK; x < x_in + SIZE/4; x++){
        for(y = y_in + SIZE/2; y < y_in + SIZE*2/3; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis tengah2 ke bawah
    for(x = x_in + SIZE/3 - THICK; x < x_in + SIZE/3; x++){
        for(y = y_in + SIZE*2/3; y < y_in + SIZE*5/6; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis tengah3 ke bawah
    for(x = x_in + SIZE*2/5 - THICK; x < x_in + SIZE*2/5; x++){
        for(y = y_in + SIZE*5/6; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis bawah ke kanan
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in + SIZE/2 - THICK; y < y_in + SIZE/2; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
}

void printS(int x_in, int y_in, int r, int g, int b, int t){
    int x,y,z,x1,x2,y1,y2;
    initFbp();
    //Garis vertical bagian kiri
    for(y=y_in;y<y_in+SIZE/2;y++){
        for(x=x_in;x<x_in+THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis vertical bagian kanan
    for(y=y_in+SIZE/2;y<y_in+SIZE;y++){
        for(x=x_in+SIZE/2-THICK;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis horizontal paling atas
    for(y=y_in;y<y_in+THICK;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);  
        }
    }
    //Garis hortizontal bagian tengah
    for(y=y_in+SIZE/2-THICK/2;y<y_in+SIZE/2+THICK/2;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis hortizontal paling bawah
    for(y=y_in+SIZE-THICK;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
}

void printT(int x_in, int y_in, int r, int g, int b, int t){
    int x,y;
    initFbp();
    //Garis horizontal
    for(y=y_in;y<y_in+THICK;y++){
        for(x=x_in;x<x_in+SIZE;x++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    //Garis vertikal
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in+SIZE/2-THICK/2;x<x_in+SIZE/2+THICK/2;x++){
            fillPixel(x, y, r, g, b, t);
        }
    }
}

void printU(int x_in, int y_in, int r, int g, int b, int t){
    int x, y;
    //Garis kiri ke bawah
    for(x = x_in; x < x_in + THICK; x++){
        for(y = y_in; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kanan ke bawah
    for(x = x_in + SIZE/2 - THICK; x < x_in + SIZE/2; x++){
        for(y = y_in; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis bawah ke kanan
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in + SIZE - THICK; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
}

//BELUM
void printV(int x_in, int y_in, int r, int g, int b, int t){
    int x, y;
    //Garis kiri1 ke bawah
    for(x = x_in; x < x_in + THICK; x++){
        for(y = y_in; y < y_in + SIZE*2/3; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kiri2 ke bawah
    for(x = x_in + THICK; x < x_in + 2*THICK; x++){
        for(y = y_in + SIZE*2/3; y < y_in + SIZE*5/6; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kiri3 ke bawah
    for(x = x_in + 2*THICK; x < x_in + 3*THICK; x++){
        for(y = y_in + SIZE*5/6; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kanan1 ke bawah
    for(x = x_in + 3*THICK; x < x_in + 4*THICK; x++){
        for(y = y_in + SIZE*5/6; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kanan2 ke bawah
    for(x = x_in + 4*THICK; x < x_in + 5*THICK; x++){
        for(y = y_in + SIZE*2/3; y < y_in + SIZE*5/6; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kanan3 ke bawah
    for(x = x_in + 5*THICK; x < x_in + 6*THICK; x++){
        for(y = y_in; y < y_in + SIZE*2/3; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
}

void printW(int x_in, int y_in, int r, int g, int b, int t){
    int x,y,z,x1,x2,y1,y2;
    initFbp();
    for(z=0;z<4;z++){
	if (z == 0) { //Garis vertikal kiri
	    x1 = x_in; x2 = x_in+THICK; y1 = y_in; y2 = y_in+SIZE-THICK;
	} else if (z == 1) { //Garis vertikal tengah
	    x1 = x_in+3*SIZE/8-THICK/2; x2 = x_in+3*SIZE/8+THICK/2; y1 = y_in+SIZE/2; y2 = y_in+SIZE-THICK;
	} else if (z == 2) { //Garis vertikal kanan
	    x1 = x_in+3*SIZE/4-THICK; x2 = x_in+3*SIZE/4; y1 = y_in; y2 = y_in+SIZE-THICK;
	} else if (z == 3) { //Garis horizontal bawah
	    x1 = x_in+THICK; x2 = x_in+3*SIZE/4-THICK; y1 = y_in+SIZE-THICK; y2 = y_in+SIZE;
	}
        for(y=y1;y<y2;y++){
            for(x=x1;x<x2;x++){
                fillPixel(x, y, r, g, b, t);
            }
        }
    }
}

void printX(int x_in, int y_in, int r, int g, int b, int t){
    int x, y;
    //Garis kiri1 ke bawah
    for(x = x_in; x < x_in + THICK; x++){
        for(y = y_in; y < y_in + SIZE/5; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kiri2 ke bawah
    for(x = x_in + THICK; x < x_in + 2*THICK; x++){
        for(y = y_in + SIZE/5; y < y_in + SIZE*2/5; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kiri3 ke bawah
    for(x = x_in; x < x_in + THICK; x++){
        for(y = y_in + SIZE*4/5; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kiri4 ke bawah
    for(x = x_in + THICK; x < x_in + 2*THICK; x++){
        for(y = y_in + SIZE*3/5; y < y_in + SIZE*4/5; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    // Garis tengah
    for(x = x_in + THICK*2; x < x_in + 3*THICK; x++){
        for(y = y_in + SIZE*2/5; y < y_in + SIZE*3/5; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }    

    // Garis kanan1 ke bawah
    for(x = x_in + THICK*3; x < x_in + THICK*4; x++){
        for(y = y_in + SIZE/5; y < y_in + SIZE*2/5; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kanan2 ke bawah
    for(x = x_in + THICK*4; x < x_in + 5*THICK; x++){
        for(y = y_in; y < y_in + SIZE/5; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    // Garis kanan3 ke bawah
    for(x = x_in + THICK*3; x < x_in + THICK*4; x++){
        for(y = y_in + SIZE*3/5; y < y_in + SIZE*4/5; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kanan4 ke bawah
    for(x = x_in + THICK*4; x < x_in + 5*THICK; x++){
        for(y = y_in + SIZE*4/5; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
}

void printY(int x_in, int y_in, int r, int g, int b, int t){
    int x, y;
    //Garis kiri1 ke bawah
    for(x = x_in; x < x_in + THICK; x++){
        for(y = y_in; y < y_in + SIZE/5; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kiri2 ke bawah
    for(x = x_in + THICK; x < x_in + 2*THICK; x++){
        for(y = y_in + SIZE/5; y < y_in + SIZE*2/5; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    // Garis tengah
    for(x = x_in + THICK*2; x < x_in + 3*THICK; x++){
        for(y = y_in + SIZE*2/5; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    // Garis kanan1 ke bawah
    for(x = x_in + THICK*3; x < x_in + THICK*4; x++){
        for(y = y_in + SIZE/5; y < y_in + SIZE*2/5; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kanan2 ke bawah
    for(x = x_in + THICK*4; x < x_in + 5*THICK; x++){
        for(y = y_in; y < y_in + SIZE/5; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
}

void printZ(int x_in, int y_in, int r, int g, int b, int t){
    int x,y,z,x1,x2,y1,y2;
    initFbp();
    for(z=0;z<7;z++){
	if (z == 0) { //Garis horizontal atas
	    x1 = x_in; x2 = x_in+SIZE/2; y1 = y_in; y2 = y_in+THICK;
	} else if (z == 1) { //Garis miring 1
	    x1 = x_in+4*SIZE/10; x2 = x_in+SIZE/2; y1 = y_in+THICK; y2 = y_in+THICK+(SIZE-2*THICK)/5;
	} else if (z == 2) { //Garis miring 2
	    x1 = x_in+3*SIZE/10; x2 = x_in+4*SIZE/10; y1 = y_in+THICK+(SIZE-2*THICK)/5; y2 = y_in+THICK+2*(SIZE-2*THICK)/5;
	} else if (z == 3) { //Garis miring 3
	    x1 = x_in+2*SIZE/10; x2 = x_in+3*SIZE/10; y1 = y_in+THICK+2*(SIZE-2*THICK)/5; y2 = y_in+THICK+3*(SIZE-2*THICK)/5;
	} else if (z == 4) { //Garis miring 4
	    x1 = x_in+SIZE/10; x2 = x_in+2*SIZE/10; y1 = y_in+THICK+3*(SIZE-2*THICK)/5; y2 = y_in+THICK+4*(SIZE-2*THICK)/5;
	} else if (z == 5) { //Garis miring 5
	    x1 = x_in; x2 = x_in+SIZE/10; y1 = y_in+THICK+4*(SIZE-2*THICK)/5; y2 = y_in+SIZE-THICK;
	} else if (z == 6) { //Garis horizontal bawah
	    x1 = x_in; x2 = x_in+SIZE/2; y1 = y_in+SIZE-THICK; y2 = y_in+SIZE;
	}
        for(y=y1;y<y2;y++){
            for(x=x1;x<x2;x++){
                fillPixel(x, y, r, g, b, t);
            }
        }
    }
}

//BELUM
void print0(int x_in, int y_in, int r, int g, int b, int t){
    int x, y;
    //Garis kiri ke bawah
    for(x = x_in; x < x_in + THICK; x++){
        for(y = y_in; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis atas ke kanan
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in; y < y_in + THICK; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kanan ke bawah
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis bawah ke kanan
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in + SIZE - THICK; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

}

void print1(int x_in, int y_in, int r, int g, int b, int t){
    int x,y;
    //Garis tengah ke bawah
    for(x = x_in + SIZE/4 - THICK; x < x_in + SIZE/4; x++){
        for(y = y_in; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    //Garis bawah ke kanan
    for(x = x_in; x < x_in + SIZE/4 + THICK; x++){
        for(y = y_in + SIZE - THICK; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    for(x = x_in + SIZE/4 - 2*THICK; x < x_in +SIZE/4 - THICK; x++){
        for(y = y_in + THICK; y < y_in + 2*THICK; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
}

void print2(int x_in, int y_in, int r, int g, int b, int t){
    int x,y;
    initFbp();
    //Garis horizontal atas
    for(y=y_in;y<y_in+THICK;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    //Garis vertikal bagian kanan
    for(y=y_in;y<y_in+SIZE/3;y++){
        for(x=x_in+SIZE/2-THICK;x<x_in+SIZE/2;x++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Dari kanan ke kiri
    for(x = x_in + SIZE/2 - 2*THICK; x < x_in + SIZE/2 - THICK; x++){
        for(y = y_in + SIZE/3; y < y_in + 2*SIZE/4; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    
    for(x = x_in + 2*THICK; x < x_in + SIZE/2 - 2*THICK; x++){
        for(y = y_in + 2*SIZE/4; y < y_in + 6*SIZE/10; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    for(x = x_in + THICK; x < x_in + 2*THICK; x++){
        for(y = y_in + 6*SIZE/10; y < y_in + SIZE-2*THICK; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    for(x = x_in;x<x_in+THICK;x++){
        for(y = y_in+SIZE-2*THICK;y<y_in+SIZE-THICK;y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    /*//Garis horizontal tengah
    for(y=y_in+SIZE/2-THICK/2;y<y_in+SIZE/2+THICK/2;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    //Garis vertikal kiri
    for(y=y_in+SIZE/2;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+THICK;x++){
            fillPixel(x, y, r, g, b, t);
        }
    }*/

    //Garis horizontal bawah
    for(y=y_in+SIZE-THICK;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    //Hapus kiri atas
    for(y=y_in;y<y_in+THICK/2;y++){
        for(x=x_in;x<x_in+SIZE/16;x++){
            fillPixel(x, y, 0, 0, 0, 0);
        }
    }
    //Hapus kanan atas
    for(y=y_in;y<y_in+THICK/2;y++){
        for(x=x_in+SIZE/2-THICK/2;x<x_in+SIZE/2;x++){
            fillPixel(x, y, 0, 0, 0, 0);
        }
    }

}

void print3(int x_in, int y_in, int r, int g, int b, int t){
    int x,y,z,x1,x2,y1,y2;
    initFbp();
    //Garis ke bawah
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in+SIZE/2;x<x_in+SIZE/2+THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis horizontal paling atas
    for(y=y_in;y<y_in+THICK;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);  
        }
    }
    //Garis hortizontal bagian tengah
    for(y=y_in+SIZE/2-THICK/2;y<y_in+SIZE/2+THICK/2;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis hortizontal paling bawah
    for(y=y_in+SIZE-THICK;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
}

void print4(int x_in, int y_in, int r, int g, int b, int t){
    int x,y,z,x1,x2,y1,y2;
    initFbp();
    for(z=0;z<3;z++){
	if (z == 0) { //Garis vertikal kiri
	    x1 = x_in; x2 = x_in+THICK; y1 = y_in; y2 = y_in+SIZE/2;
	} else if (z == 1) { //Garis horizontal tengah
	    x1 = x_in; x2 = x_in+SIZE/2; y1 = y_in+SIZE/2-THICK/2; y2 = y_in+SIZE/2+THICK/2;
	} else if (z == 2) { //Garis vertikal kanan
	    x1 = x_in+SIZE/2-THICK; x2 = x_in+SIZE/2; y1 = y_in; y2 = y_in+SIZE;
	}
        for(y=y1;y<y2;y++){
            for(x=x1;x<x2;x++){
                fillPixel(x, y, r, g, b, t);
            }
        }
    }

}

void print5(int x_in, int y_in, int r, int g, int b, int t){
    int x,y,z,x1,x2,y1,y2;
    initFbp();
    for(z=0;z<6;z++){
	if (z == 0) { //Garis vertikal kiri atas
	    x1 = x_in; x2 = x_in+THICK; y1 = y_in; y2 = y_in+SIZE/2+THICK/2;
	} else if (z == 1) { //Garis horizontal atas
	    x1 = x_in; x2 = x_in+SIZE/2; y1 = y_in; y2 = y_in+THICK;
	} else if (z == 2) { //Garis horizontal tengah
	    x1 = x_in; x2 = x_in+SIZE/2-THICK; y1 = y_in+SIZE/2-THICK/2; y2 = y_in+SIZE/2+THICK/2;
	} else if (z == 3) { //Garis vertikal kanan
	    x1 = x_in+SIZE/2-THICK; x2 = x_in+SIZE/2; y1 = y_in+SIZE/2+THICK/2; y2 = y_in+SIZE-THICK;
	} else if (z == 4) { //Garis horizontal bawah
	    x1 = x_in+THICK; x2 = x_in+SIZE/2-THICK; y1 = y_in+SIZE-THICK; y2 = y_in+SIZE;
	} else if (z == 5) { //Garis vertikal kiri bawah
	    x1 = x_in; x2 = x_in+THICK; y1 = y_in+3*SIZE/4; y2 = y_in+SIZE-THICK;
	}
        for(y=y1;y<y2;y++){
            for(x=x1;x<x2;x++){
                fillPixel(x, y, r, g, b, t);
            }
        }
    }
}

//BELUM
void print6(int x_in, int y_in, int r, int g, int b, int t){
    int x, y;
    //Garis kiri ke bawah
    for(x = x_in; x < x_in + THICK; x++){
        for(y = y_in; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis atas ke kanan
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in; y < y_in + THICK; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis tengah ke kanan
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in + SIZE/2 - THICK/2; y < y_in + SIZE/2 + THICK/2; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis kanan ke bawah
    for(x = x_in + SIZE/2 - THICK; x < x_in + SIZE/2; x++){
        for(y = y_in + SIZE/2; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }

    //Garis bawah ke kanan
    for(x = x_in; x < x_in + SIZE/2; x++){
        for(y = y_in + SIZE - THICK; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
}

void print7(int x_in, int y_in, int r, int g, int b, int t){
    int x,y;
    //Garis atas ke kanan
    for(x = x_in; x < x_in + SIZE/4 + 3*THICK; x++){
        for(y = y_in; y < y_in + THICK; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    //Garis kanan atas ke bawah
    for(x = x_in + SIZE/4 + 2*THICK; x < x_in + SIZE/4 + 3*THICK; x++){
        for(y = y_in; y < y_in + 2*THICK; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    for(x = x_in + SIZE/4 + THICK; x < x_in + SIZE/4 + 2*THICK; x++){
        for(y = y_in + 2*THICK; y < y_in + 4*THICK; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    for(x = x_in + SIZE/4; x < x_in + SIZE/4 + THICK; x++){
        for(y = y_in + 4*THICK; y < y_in + 6*THICK; y++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    for(x = x_in + SIZE/4 - THICK; x < x_in + SIZE/4; x++){
        for(y = y_in + 6*THICK; y < y_in + SIZE; y++){
            fillPixel(x, y, r, g, b, t);
        }
    } 
}

void print8(int x_in, int y_in, int r, int g, int b, int t){
    int x,y;
    initFbp();
    //Garis vertikal kiri
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+THICK;x++){
            fillPixel(x, y, r, g, b, t);
        }
    }  
    //Garis vertikal kanan 
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in+SIZE/2-THICK;x<x_in+SIZE/2;x++){
            fillPixel(x, y, r, g, b, t);
        }
    } 
    //Garis horizontal atas
    for(y=y_in;y<y_in+THICK;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x, y, r, g, b, t);
        }
    }  
    //Garis horizontal tengah
    for(y=y_in+SIZE/2-THICK/2;y<y_in+SIZE/2+THICK/2;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    //Garis horizontal bawah
    for(y=y_in+SIZE-THICK;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x, y, r, g, b, t);
        }
    }
    //Hapus kiri atas
    for(y=y_in;y<y_in+THICK;y++){
        for(x=x_in;x<x_in+THICK/2;x++){
            fillPixel(x, y, 0, 0, 0, 0);
        }
    }
    //Hapus kiri tengah
    for(y=y_in+SIZE/2-THICK/2;y<y_in+SIZE/2+THICK/2;y++){
        for(x=x_in;x<x_in+THICK/2;x++){
            fillPixel(x, y, 0, 0, 0, 0);
        }
    }
    //Hapus kiri bawah
    for(y=y_in+SIZE-THICK;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+THICK/2;x++){
            fillPixel(x, y, 0, 0, 0, 0);
        }
    }
    //Hapus kanan atas
    for(y=y_in;y<y_in+THICK;y++){
        for(x=x_in+SIZE/2-THICK/2;x<x_in+SIZE/2;x++){
            fillPixel(x, y, 0, 0, 0, 0);
        }
    }
    //Hapus kanan tengah  
    for(y=y_in+SIZE/2-THICK/2;y<y_in+SIZE/2+THICK/2;y++){
        for(x=x_in+SIZE/2-THICK/2;x<x_in+SIZE/2;x++){
            fillPixel(x, y, 0, 0, 0, 0);
        }
    }
    //Hapus kanan bawah
    for(y=y_in+SIZE-THICK;y<y_in+SIZE;y++){
        for(x=x_in+SIZE/2-THICK/2;x<x_in+SIZE/2;x++){
            fillPixel(x, y, 0, 0, 0, 0);
        }
    }
}

void print9(int x_in, int y_in, int r, int g, int b, int t){
    int x,y,z,x1,x2,y1,y2;
    initFbp();
    //Garis vertical bagian kiri
    for(y=y_in;y<y_in+SIZE/2;y++){
        for(x=x_in;x<x_in+THICK;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis vertical bagian kanan
    for(y=y_in;y<y_in+SIZE;y++){
        for(x=x_in+SIZE/2-THICK;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis horizontal paling atas
    for(y=y_in;y<y_in+THICK;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);  
        }
    }
    //Garis hortizontal bagian tengah
    for(y=y_in+SIZE/2-THICK/2;y<y_in+SIZE/2+THICK/2;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
    //Garis hortizontal paling bawah
    for(y=y_in+SIZE-THICK;y<y_in+SIZE;y++){
        for(x=x_in;x<x_in+SIZE/2;x++){
            fillPixel(x,y,r,g,b,t);
        }
    }
}

void printNama(char* name, int x_in, int y_in, int r, int g, int b, int t) {
    for (int i = 0; i < strlen(name); i++) {
        switch (name[i]) {
            case 'a' :
                printA(x_in, y_in, r, g, b, t);
                break;
            case 'b' :
                printB(x_in, y_in, r, g, b, t);
                break;
            case 'c' :
                printC(x_in, y_in, r, g, b, t);
                break;       
            case 'd' :
                printD(x_in, y_in, r, g, b, t);
                break;        
            case 'e' :
                printE(x_in, y_in, r, g, b, t);
                break;        
            case 'f' :
                printF(x_in, y_in, r, g, b, t);
                break;        
            case 'g' :
                printG(x_in, y_in, r, g, b, t);
                break;        
            case 'h' :
                printH(x_in, y_in, r, g, b, t);
                break;        
            case 'i' :
                printI(x_in, y_in, r, g, b, t);
                break;        
            case 'j' :
                printJ(x_in, y_in, r, g, b, t);
                break;        
            case 'k' :
                printK(x_in, y_in, r, g, b, t);
                break;        
            case 'l' :
                printL(x_in, y_in, r, g, b, t);
                break;        
            case 'm' :
                printM(x_in, y_in, r, g, b, t);
                break;        
            case 'n' :
                printN(x_in, y_in, r, g, b, t);
                break;        
            case 'o' :
                printO(x_in, y_in, r, g, b, t);
                break;        
            case 'p' :
                printP(x_in, y_in, r, g, b, t);
                break;        
            case 'q' :
                printQ(x_in, y_in, r, g, b, t);
                break;        
            case 'r' :
                printR(x_in, y_in, r, g, b, t);
                break;        
            case 's' :
                printS(x_in, y_in, r, g, b, t);
                break;        
            case 't' :
                printT(x_in, y_in, r, g, b, t);
                break;        
            case 'u' :
                printU(x_in, y_in, r, g, b, t);
                break;        
            case 'v' :
                printV(x_in, y_in, r, g, b, t);
                break;        
            case 'w' :
                printW(x_in, y_in, r, g, b, t);
                break;        
            case 'x' :
                printX(x_in, y_in, r, g, b, t);
                break;        
            case 'y' :
                printY(x_in, y_in, r, g, b, t);
                break;        
            case 'z' :
                printZ(x_in, y_in, r, g, b, t);
                break;        
            case '0' :
                print0(x_in, y_in, r, g, b, t);
                break;        
            case '1' :
                print1(x_in, y_in, r, g, b, t);
                break;        
            case '2' :
                print2(x_in, y_in, r, g, b, t);
                break;        
            case '3' :
                print3(x_in, y_in, r, g, b, t);
                break;        
            case '4' :
                print4(x_in, y_in, r, g, b, t);
                break;        
            case '5' :
                print5(x_in, y_in, r, g, b, t);
                break;        
            case '6' :
                print6(x_in, y_in, r, g, b, t);
                break;        
            case '7' :
                print7(x_in, y_in, r, g, b, t);
                break;        
            case '8' :
                print8(x_in, y_in, r, g, b, t);
                break;        
            case '9' :
                print9(x_in, y_in, r, g, b, t);
                break;        
            
            
        }

        if (name[i] == 'i' || name[i] == 'I') {
            x_in += 20;
        } else if (name[i] == 'w' || name[i] == 'W') {
            x_in += SIZE/2 + 30;
        } else if (name[i] == 'v' || name[i] == 'V') {
            x_in += SIZE/2 + 15;
        } else {
            x_in += SIZE/2 + 10;
        }
    }
}