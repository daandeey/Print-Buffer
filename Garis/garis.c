#include <math.h> 
#include "garis.h"

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

void printLingkaran(int x, int y, int r)
{
    int i, x1, y1;
    for (i = 0; i <= 720; i++)
    {
        x1 = (int) x + nearbyint(r * cos(i * PI / 360));
        y1 = (int) y + nearbyint(r * sin(i * PI / 360));

        fillPixel(x1, y1, 255, 255, 0, 0);
    }
}

void printMatahari(int x, int y, int r, int d){
    //lingkaran
    int i;
    int x1, x2, y1, y2;

    printLingkaran(x, y, r);

    
    i = 0;

    x1 = (int) x + nearbyint(r * cos(i * PI / 180));
    y1 = (int) y + nearbyint(r * sin(i * PI / 180));
    for (i = 60; i<=360; i+=60)
    {
        x2 = (int) x + nearbyint(r * cos(i * PI / 180));
        y2 = (int) y + nearbyint(r * sin(i * PI / 180));

        printGaris(x1, y1, x2, y2, 255, 255, 255 ,0);

        x1 = x2;
        y1 = y2;
    } 



    //garis kecil
    
    for (i = 0; i<=360; i += 15)
    {
        x1 = (int) x + nearbyint(r * cos(i * PI / 180));
        x2 = (int) x + nearbyint((r + d) * cos(i * PI / 180));
        y1 = (int) y + nearbyint(r * sin(i * PI / 180));
        y2 = (int) y + nearbyint((r + d) * sin(i * PI / 180));

        if (x1 < x2)
        {
            printGaris(x1, y1, x2, y2, 255, 255, 0, 0);
        }
        else
        {
            printGaris(x2, y2, x1, y1, 255, 255, 0, 0);
        }
    }
}

void printGunung(int x0, int y0){
    printGaris(2+x0, 201+y0, 135+x0, 13+y0, 0, 102, 204, 0);
    printGaris(135+x0, 13+y0, 289+x0, 203+y0, 0, 102, 204, 0);
    printGaris(262+x0, 165+y0, 375+x0, 7+y0, 0, 102, 204, 0);
    printGaris(375+x0, 7+y0, 559+x0, 203+y0, 0, 102, 204, 0);
    printGaris(2+x0, 201+y0, 559+x0, 203+y0, 0, 102, 204, 0);

}

void printJalan(int x0, int y0){
    printGaris(x0+268,y0+206,x0+335,y0+390,153,76,0,0);
    printGaris(x0+305,y0+206,x0+449,y0+390,153,76,0,0);
    printGaris(295+x0, 221+y0, 311+x0, 252+y0,153,76,0,0);
    printGaris(327+x0, 274+y0, 345+x0, 303+y0,153,76,0,0);
    printGaris(354+x0, 322+y0, 376+x0, 360+y0,153,76,0,0);
}

void printSawahL(int x0, int y0){
//(x0, y0) titik awal sawah
//n menyatakan banyak garis, r menyatakan jarak antara 2 garis
    int x0_h, x0_v;
    int y0_h;

    x0_h = x0;
    x0_v = x0;
    y0_h = y0;
    //garis horizontal
    for (int i=0;i<4;i++){
        printGaris(52+x0_h, 244+y0_h, 241+x0_h, 244+y0_h, 127, 247, 29, 0);
        x0_h+=10;
        y0_h+=24;
    }
    //garis vertikal
    for (int i=0;i<6;i++){
        printGaris(64+x0_v, 226+y0, 116+x0_v, 333+y0, 127, 247, 29, 0);
        x0_v+=29;
    } 
 }

void printSawahR(int x0, int y0){
//(x0, y0) titik awal sawah
//n menyatakan banyak garis, r menyatakan jarak antara 2 garis
    int x0_h, x0_v;
    int y0_h;

    x0_h = x0;
    x0_v = x0;
    y0_h = y0;
    //garis horizontal
    for (int i=0;i<4;i++){
        printGaris(383+x0_h, 244+y0_h, 578+x0_h, 244+y0_h, 127, 247, 29, 0);
        x0_h+=10;
        y0_h+=24;
    }

    //garis vertikal
    for (int i=0;i<6;i++){
        printGaris(395+x0_v, 226+y0, 447+x0_v, 333+y0, 127, 247, 29, 0);
        x0_v+=29;
    } 
 }

void printSawah(int x0_L, int x0_R, int y0){
    printSawahL(x0_L, y0);
    printSawahR(x0_R, y0);
    
}

void printSetengahAtasLingkaran(int xp, int yp, int z, int r, int g, int b, int t)
{
    //Mencetak setengah atas lingkaran dengan titik pusat <xp, yp> dan jari-jari Z
    int x, x1, x2;
    int y;

    for (x = xp - z; x <= xp + z; x++)
    {
        y = yp - sqrt(pow(z, 2) - pow(x - xp, 2));

        fillPixel(x, y, r, g, b, t);
    }

    for (y = yp - z; y <= yp; y++)
    {
        x1 = xp + sqrt(pow(z, 2) - pow(y - yp, 2));
        x2 = xp - sqrt(pow(z, 2) - pow(y - yp, 2));

        fillPixel(x1, y, r, g, b, t);
        fillPixel(x2, y, r, g, b, t);
    }
}

void printSetengahBawahElips(int xp, int yp, int p, int q, int r, int g, int b, int t)
{
    //Mencetak setengah bawah elips dengan titik pusat <xp, yp> dengan jari-jari <p, q>
    int x, x1, x2;
    int y;

    for (x = xp - p; x <= xp + p; x++)
    {
        y = yp + sqrt( (pow(p, 2) - pow(x - xp, 2)) * pow((double) q/p, 2));

        fillPixel(x, y, r, g, b, t);
    }

    for (y = yp; y <= yp + q; y++)
    {
        x1 = xp + sqrt((pow(q, 2) - pow(y - yp, 2)) * pow((double) p/q, 2));
        x2 = xp - sqrt((pow(q, 2) - pow(y - yp, 2)) * pow((double) p/q, 2));

        fillPixel(x1, y, r, g, b, t);
        fillPixel(x2, y, r, g, b, t);
    }
}


void printAwan(int xp, int yp, int p, int q, int r, int g, int b, int t)
{
    printSetengahBawahElips(xp, yp, p, q, r, g, b, t);

    int z1 = 2 * p / 9;
    int x1 = xp - p + z1;
    printSetengahAtasLingkaran(x1, yp, z1, r, g, b, t);

    int z2 = 4 * p / 9;
    int x2 = x1 + z1 + z2;
    printSetengahAtasLingkaran(x2, yp, z2, r, g, b, t);

    int z3 = p - z1 - z2;
    int x3 = x2 + z2 + z3;
    printSetengahAtasLingkaran(x3, yp, z3, r, g, b, t);
}
