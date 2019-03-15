#include <math.h>
#include "framebuffer.h"

#ifndef SHAPE_H
#define SHAPE_H

#define PI 3.14159265

void printGaris(int x0, int y0, int x1, int y1, int r, int g, int b, int t);
void printPersegiPanjang(int x1, int y1, int x2, int y2, int r, int g, int b, int t);
void printSegitiga(int x1, int y1, int x2, int y2, int x3, int y3, int r, int g, int b, int t);
void printBangunan(int x, int y, float k,  int r, int g, int b, int t);
void printLingkaran(int xp, int yp, int z, int r, int g, int b, int t);
void printBulanSabit(int xp, int yp, int z, int r, int g, int b, int t);
void printPoligon(int xp, int yp, int n, int p, int q, int deg, int r, int g, int b, int t);
void printTank(int x, int y, int len, int r, int g, int b, int t);
void printBullet(int x, int y, int z, int n, int r, int g, int b, int t);
void printHalfElips(int xp, int yp, int p, int q, int r, int g, int b, int t);
void printPesawat(int x, int y, float scale, int r, int g, int b, int t);
void printRudal(int x,int y,int dx, int dy, int r,int g,int b, int t);

#endif