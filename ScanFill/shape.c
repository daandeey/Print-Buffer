#include "shape.h"

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

void printPersegiPanjang(int x1, int y1, int x2, int y2, int r, int g, int b, int t)
{
    //Mencetak persegi panjang dengan titik awal <x1, y1> ke titik akhir <x2, y2>
    printGaris(x1, y1, x2, y1, r, g, b, t);
    printGaris(x1, y1, x1, y2, r, g, b, t);
    printGaris(x1, y2, x2, y2, r, g, b, t);
    printGaris(x2, y1, x2, y2, r, g, b, t);

    floodFillPixel((int)((x1 + x2) / 2), (int)((y1 + y2) / 2), 0, 0, 0, 0, r, g, b, t);
}

void printSegitiga(int x1, int y1, int x2, int y2, int x3, int y3, int r, int g, int b, int t)
{
    //Mencetak segitiga berdasarkan masukan tiga titik
    printGaris(x1, y1, x2, y2, r, g, b, t);
    printGaris(x1, y1, x3, y3, r, g, b, t);
    printGaris(x2, y2, x3, y3, r, g, b, t);

    floodFillPixel((int)((x1 + x2 + x3) / 3), (int)((y1 + y2 + y3) / 3), 0, 0, 0, 0, r, g, b, t);
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

    floodFillPixel(xp, yp, 0, 0, 0, 0, 128, 0, 0, 0);
}

void printBulanSabit(int xp, int yp, int z, int r, int g, int b, int t)
{
    printLingkaran(xp, yp, z, r, g, b, t);
    printLingkaran(xp - 2*z/3, yp, z, r, g, b, t);
    
    floodFillPixel(xp + 2*z/3, yp, 0, 0, 0, 0, r, g, b, t);

    printLingkaran(xp, yp, z, 0, 0, 0, 0);
    printLingkaran(xp - 2*z/3, yp, z, 0, 0, 0, 0);
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

        printGaris(x1, y1, x2, y2, r, g, b, t);

        x1 = x2;
        y1 = y2;
    }

    floodFillPixel(xp, yp, 0, 0, 0, 0, r, g, b, t);
}

void printTank(int x, int y, int len, int r, int g, int b, int t)
{
    int tinggi_kepala = floor(0.75 * len);
    int y0 = y - ceil(sqrt(3) / 2 * len);

    printPoligon(x, y, 6, len, len * 3, 30, r, g, b, t); //Print Badan Tank
    printPersegiPanjang(x - len, y0 - tinggi_kepala, x + len, y0, r, g, b, t); //Print Kepala Tank
    printPersegiPanjang(x + len, y0 - floor(0.6 * tinggi_kepala), x + 3 * len, y0 - floor(0.4 * tinggi_kepala), r, g, b, t); //Print Tembakan Tank
}

void printBullet(int x, int y, int z, int n, int r, int g, int b, int t)
{
    for (int i = 0; i < n; i++) {
        printLingkaran(x, y, z, r, g, b, t);
        floodFillPixel(x, y, 0, 0, 0, 0, r, g, b, t);
        x += 50;
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

void printPesawat(int x, int y, float scale, int r, int g, int b, int t)
{
    printGaris(x+floor(72.5*scale), y-floor(30*scale), x-floor(125*scale), y-floor(30*scale), r, g, b, t);
    printGaris(x+floor(72.5*scale), y+floor(30*scale), x-floor(125*scale), y+floor(30*scale), r, g, b, t);
    printHalfElips(x+floor(72.5*scale), y, floor(50*scale), floor(30*scale), r, g, b, t);
    printGaris(x-floor(125*scale), y-floor(30*scale), x-floor(125*scale), y-floor(10*scale), r, g, b, t);
    printGaris(x-floor(125*scale), y+floor(30*scale), x-floor(125*scale), y+floor(10*scale), r, g, b, t);
    printPersegiPanjang(x-floor(145*scale), y-floor(10*scale), x-floor(82.5*scale), y+floor(10*scale), r, g, b, t);

    printSegitiga(x+floor(52.5*scale), y-floor(30*scale), x-floor(42.5*scale), y-floor(175*scale), x-floor(42.5*scale), y-floor(30*scale), r, g, b, t);
    printSegitiga(x+floor(52.5*scale), y+floor(30*scale), x-floor(42.5*scale), y+floor(175*scale), x-floor(42.5*scale), y+floor(30*scale), r, g, b, t);

    printSegitiga(x-floor(82.5*scale), y-floor(30*scale), x-floor(125*scale), y-floor(30*scale), x-floor(125*scale), y-floor(75*scale), r, g, b, t);
    printSegitiga(x-floor(82.5*scale), y+floor(30*scale), x-floor(125*scale), y+floor(30*scale), x-floor(125*scale), y+floor(75*scale), r, g, b, t);
}

void printRudal(int x,int y,int dx, int dy, int r,int g,int b, int t)
{
    printSegitiga(x-(5 * dx), y+(15*dy),x, y+(20*dy), x+(5*dx), y+(15*dy), r, g, b, t);
    printPersegiPanjang(x-(5*dx), y, x+(dx*5), y+(15*dy), r, g, b, t);
    printSegitiga(x-(10*dx), y, x-(5*dx), y, x-(5*dx), y+(10*dy), r, g, b, t);
    printSegitiga(x+(10*dx), y, x+(5*dx), y, x+(5*dx), y+(10*dy), r, g, b, t);
}