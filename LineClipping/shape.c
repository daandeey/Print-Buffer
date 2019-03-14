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

int INSIDE = 0; // 0000 
int LEFT = 1;   // 0001 
int RIGHT = 2;  // 0010 
int BOTTOM = 4; // 0100 
int TOP = 8;    // 1000 

const int x_max = 820; 
const int y_max = 680; 
const int x_min = 80; 
const int y_min = 80; 

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

void drawFrame() {

    printGaris(x_min, y_min , x_max, y_min, 255, 255, 255, 0);
    printGaris(x_min, y_min , x_min, y_max, 255, 255, 255, 0);
    printGaris(x_min, y_max , x_max, y_max, 255, 255, 255, 0);
    printGaris(x_max, y_max , x_max, y_min, 255, 255, 255, 0);
}

int getRegionCode(int x, int y) { 
    int code = 0; // 0000

    if (x < x_min) code |= 1; // 0001
    else if (x > x_max) code |= 2; // 0010

    if (y < y_min) code |= 4; // 0100
    else if (y > y_max) code |= 8; // 1000

    return code; 
} 

/*
    ref: 
*/

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
        drawFrame();
        printGaris(x1, y1, x2, y2, r, g, b, t);
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

        clip(x1, y1, x2, y2, r, g, b, t);

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

void printHalfElips(int xp, int yp, int p, int q, int r, int g, int b, int t)
{
    //Mencetak setengah elips dengan titik pusat <xp, yp> dengan jari-jari <p, q>
    int x, x1, x2;
    int y, y1, y2;

    for (x = xp - p; x <= xp + p; x++)
    {
        y1 = yp + sqrt( (pow(p, 2) - pow(x - xp, 2)) * pow((double) q/p, 2));
        y2 = yp - sqrt( (pow(p, 2) - pow(x - xp, 2)) * pow((double) q/p, 2));

        if (x >= xp) {
            fillPixel(x, y1, r, g, b, t);
            fillPixel(x, y2, r, g, b, t);
        }
        
    }

    for (y = yp - q; y <= yp + q; y++)
    {
        x1 = xp + sqrt((pow(q, 2) - pow(y - yp, 2)) * pow((double) p/q, 2));
        fillPixel(x1, y, r, g, b, t);
    }
}

void printPersegiPanjang(int x1, int y1, int x2, int y2, int r, int g, int b, int t)
{
    //Mencetak persegi panjang dengan titik awal <x1, y1> ke titik akhir <x2, y2>
    clip(x1, y1, x2, y1, r, g, b, t);
    clip(x1, y1, x1, y2, r, g, b, t);
    clip(x1, y2, x2, y2, r, g, b, t);
    clip(x2, y1, x2, y2, r, g, b, t);
}

void printPersegi(int x, int y, int d, int r, int g, int b, int t)
{
    //Mencetak persegi dengan titik awal <x, y> dengan panjang sisi d 
    printPersegiPanjang(x, y, x + d, y + d, 255, 255, 255, 0);
}

void printSegitiga(int x1, int y1, int x2, int y2, int x3, int y3, int r, int g, int b, int t)
{
    //Mencetak segitiga berdasarkan masukan tiga titik
    clip(x1, y1, x2, y2, r, g, b, t);
    clip(x1, y1, x3, y3, r, g, b, t);
    clip(x2, y2, x3, y3, r, g, b, t);

}

void printTank(int x, int y, int len, int r, int g, int b, int t) {
    int tinggi_kepala = floor(0.75 * len);
    int y0 = y - ceil(sqrt(3) / 2 * len);

    printPoligon(x, y, 6, len, len * 3, 30, r, g, b, t); //Print Badan Tank
    printPersegiPanjang(x - len, y0 - tinggi_kepala, x + len, y0, r, g, b, t); //Print Kepala Tank
    printPersegiPanjang(x + len, y0 - floor(0.6 * tinggi_kepala), x + 3 * len, y0 - floor(0.4 * tinggi_kepala), r, g, b, t); //Print Tembakan Tank
}

void printBullet(int x, int y, int z, int n, int r, int g, int b, int t) {
    for (int i = 0; i < n; i++) {
        printLingkaran(x, y, z, r, g, b, t);
        x += 50;
    }
}

void printBangunan(int x, int y, float k,  int r, int g, int b, int t) {
    printPersegiPanjang((floor(86*k)+x), (floor(206*k)+y), (floor(484*k)+x), (floor(283*k)+y), r, g, b, t);
    printPersegiPanjang((floor(230*k)+x), (floor(206*k)+y), (floor(332*k)+x), (floor(283*k)+y), r, g, b, t);
    printPersegiPanjang((floor(255*k)+x), (floor(224*k)+y), (floor(306*k)+x), (floor(283*k)+y), r, g, b, t);
    printPersegiPanjang((floor(130*k)+x), (floor(228*k)+y), (floor(175*k)+x), (floor(254*k)+y), r, g, b, t);
    printPersegiPanjang((floor(383*k)+x), (floor(224*k)+y), (floor(429*k)+x), (floor(249*k)+y), r, g, b, t);
    printPersegiPanjang((floor(205*k)+x), (floor(130*k)+y), (floor(349*k)+x), (floor(206*k)+y), r, g, b, t);
    printPersegiPanjang((floor(108*k)+x), (floor(164*k)+y), (floor(175*k)+x), (floor(206*k)+y), r, g, b, t);
    printPersegiPanjang((floor(383*k)+x), (floor(165*k)+y), (floor(451*k)+x), (floor(206*k)+y), r, g, b, t);
    printPersegiPanjang((floor(269*k)+x), (floor(150*k)+y), (floor(290*k)+x), (floor(160*k)+y), r, g, b, t);
    printPersegiPanjang((floor(204*k)+x), (floor(160*k)+y), (floor(349*k)+x), (floor(169*k)+y), r, g, b, t);
    printSegitiga((floor(214*k)+x), (floor(206*k)+y), (floor(279*k)+x), (floor(174*k)+y), (floor(345*k)+x),(floor(206*k)+y), r, g, b, t);
    printSegitiga((floor(108*k)+x), (floor(164*k)+y), (floor(143*k)+x), (floor(119*k)+y), (floor(175*k)+x),(floor(164*k)+y), r, g, b, t);
    printSegitiga((floor(383*k)+x), (floor(165*k)+y), (floor(417*k)+x), (floor(119*k)+y), (floor(451*k)+x),(floor(165*k)+y), r, g, b, t);
    printSegitiga((floor(205*k)+x), (floor(130*k)+y), (floor(277*k)+x), (floor(16*k)+y), (floor(349*k)+x),(floor(130*k)+y), r, g, b, t);
}

void printMatahari(int xp, int yp, int n, int p, int q, int deg, int r, int g, int b, int t)
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

        clip(x1, y1, x2, y2, r, g, b, t);

        int x3 = xp + (q + 10) * cos(d * PI / 180);
        int y3 = yp + (p + 10) * sin(d * PI / 180);

        clip(x2, y2, x3, y3, r, g, b, t);

        x1 = x2;
        y1 = y2;
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

void printPesawat(int x, int y, float scale, int r, int g, int b, int t) {

    clip(x+floor(72.5*scale), y-floor(30*scale), x-floor(125*scale), y-floor(30*scale), r, g, b, t);
    clip(x+floor(72.5*scale), y+floor(30*scale), x-floor(125*scale), y+floor(30*scale), r, g, b, t);
    // printHalfElips(x+floor(72.5*scale), y, floor(50*scale), floor(30*scale), r, g, b, t);
    clip(x-floor(125*scale), y-floor(30*scale), x-floor(125*scale), y-floor(10*scale), r, g, b, t);
    clip(x-floor(125*scale), y+floor(30*scale), x-floor(125*scale), y+floor(10*scale), r, g, b, t);
    printPersegiPanjang(x-floor(145*scale), y-floor(10*scale), x-floor(82.5*scale), y+floor(10*scale), r, g, b, t);

    printSegitiga(x+floor(52.5*scale), y-floor(30*scale), x-floor(42.5*scale), y-floor(175*scale), x-floor(42.5*scale), y-floor(30*scale), r, g, b, t);
    printSegitiga(x+floor(52.5*scale), y+floor(30*scale), x-floor(42.5*scale), y+floor(175*scale), x-floor(42.5*scale), y+floor(30*scale), r, g, b, t);

    printSegitiga(x-floor(82.5*scale), y-floor(30*scale), x-floor(125*scale), y-floor(30*scale), x-floor(125*scale), y-floor(75*scale), r, g, b, t);
    printSegitiga(x-floor(82.5*scale), y+floor(30*scale), x-floor(125*scale), y+floor(30*scale), x-floor(125*scale), y+floor(75*scale), r, g, b, t);
}

void printRudal(int x,int y,int dx, int dy, int r,int g,int b, int t){
    printSegitiga(x-(5 * dx), y+(15*dy),x, y+(20*dy), x+(5*dx), y+(15*dy), r, g, b, t);
    printPersegiPanjang(x-(5*dx), y, x+(dx*5), y+(15*dy), r, g, b, t);
    printSegitiga(x-(10*dx), y, x-(5*dx), y, x-(5*dx), y+(10*dy), r, g, b, t);
    printSegitiga(x+(10*dx), y, x+(5*dx), y, x+(5*dx), y+(10*dy), r, g, b, t);
}