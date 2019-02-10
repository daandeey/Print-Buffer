#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>
#include "shape.c"

void geserPoligon(int xp, int yp, int n, int p, int q, int deg, int r, int g, int b, int t, int dx, int dy, int ds)
{
    //Poligon digeser sebesar <dx, dy> selama ds detik
    int x, y;
    ds *= 60;

    for (int i = 0; i <= ds; i++)
    {
        x = nearbyint(xp + (double) (i * dx / ds));
        y = nearbyint(yp + (double) (i * dy / ds));

        printPoligon(x, y, n, p, q, deg, r, g, b, t);
        usleep(1000000 / 60);

        if (i != ds)
        {
            printPoligon(x, y, n, p, q, deg, 0, 0, 0, t);
        }
    }
}

void putarPoligon(int xp, int yp, int n, int p, int q, int deg, int r, int g, int b, int t, int dr, int ds)
{
    //Poligon diputar sebesar dr derajat selama ds detik
    int c_deg;

    ds *= 60;

    for (int i = 0; i <= ds; i++)
    {
        c_deg = nearbyint(deg + (double) (i * dr / ds));

        printPoligon(xp, yp, n, p, q, c_deg, r, g, b, t);
        usleep(1000000 / 60);
        if (i != ds)
        {
            printPoligon(xp, yp, n, p, q, c_deg, 0, 0, 0, t);
        }
    }

}

void perbesarPoligon(int xp, int yp, int n, int p, int q, int deg, int r, int g, int b, int t, float dz, int ds)
{
    //Poligion dibesarkan sebesar dz selama ds detik
    int dp, dq;

    ds *= 60;

    for(int i = 0; i<= ds; i++)
    {
        dp = nearbyint( (double) p * (1 + i * (dz - 1) / ds));
        dq = nearbyint( (double) q * (1 + i * (dz - 1) / ds));

        printPoligon(xp, yp, n, dp, dq, deg, r, g, b, t);
        usleep(1000000 / 60);
        if (i != ds)
        {
            printPoligon(xp, yp, n, dp, dq, deg, 0, 0, 0, t);
        }
    }

}

void geserLingkaran(int xp, int yp, int z, int r, int g, int b, int t, int dx, int dy, int ds)
{
    //Lingkaran digeser sebesar <dx, dy> selama ds detik
    int x, y;
    ds *= 60;

    for (int i = 0; i <= ds; i++)
    {
        x = nearbyint(xp + (double) (i * dx / ds));
        y = nearbyint(yp + (double) (i * dy / ds));

        printLingkaran(x, y, z, r, g, b, t);
        usleep(1000000 / 60);

        if (i != ds)
        {
            printLingkaran(x, y, z, 0, 0, 0, t);
        }
    }
}

void perbesarLingkaran(int xp, int yp, int z, int r, int g, int b, int t, int dz, int ds)
{
    int dr;

    ds *= 60;

    for(int i = 0; i<= ds; i++)
    {
        dr = nearbyint( (double) r * (1 + i * (dz - 1) / ds));

        printLingkaran(xp, yp, dr, r, g, b, t);
        usleep(1000000 / 60);
        if (i != ds)
        {
            printLingkaran(xp, yp, dr, 0, 0, 0, t);        
        }
    }
}

void geserSetengahAtasLingkaran(int xp,int  yp, int z, int r, int g, int b, int t, int dx, int dy, int ds)
{
    //Lingkaran digeser sebesar <dx, dy> selama ds detik
    int x, y;
    ds *= 60;

    for (int i = 0; i <= ds; i++)
    {
        x = nearbyint(xp + (double) (i * dx / ds));
        y = nearbyint(yp + (double) (i * dy / ds));

        printSetengahAtasLingkaran(x, y, z, r, g, b, t);
        usleep(1000000 / 60);

        if (i != ds)
        {
            printSetengahAtasLingkaran(x, y, z, 0, 0, 0, t);
        }
    }
}

void perbesarSetengahAtasLingkaran(int xp, int yp, int z, int r, int g, int b, int t, int dz, int ds)
{
    int dr;

    ds *= 60;

    for(int i = 0; i<= ds; i++)
    {
        dr = nearbyint( (double) r * (1 + i * (dz - 1) / ds));

        printSetengahAtasLingkaran(xp, yp, dr, r, g, b, t);
        usleep(1000000 / 60);
        if (i != ds)
        {
            printSetengahAtasLingkaran(xp, yp, dr, 0, 0, 0, t);        
        }
    }
}

void geserBullet(int xp, int yp, int z, int n, int r, int g, int b, int t, int dx, int dy, int ds)
{
    //Poligon digeser sebesar <dx, dy> selama ds detik
    int x, y;
    ds *= 60;

    for (int i = 0; i <= ds; i++)
    {
        x = nearbyint(xp + (double) (i * dx / ds));
        y = nearbyint(yp + (double) (i * dy / ds));

        printBullet(x, y, z, n, r, g, b, t);
        usleep(1000000 / 60);

        if (i != ds)
        {
            printBullet(x, y, z, n, 0, 0, 0, t);
        }
    }
}

void geserAwan(int xp, int yp, int p, int q, int r, int g, int b, int t, int dx, int dy, int ds)
{
    //Poligon digeser sebesar <dx, dy> selama ds detik
    int x, y;
    ds *= 60;

    for (int i = 0; i <= ds; i++)
    {
        x = nearbyint(xp + (double) (i * dx / ds));
        y = nearbyint(yp + (double) (i * dy / ds));

        printAwan(x, y, p, q, r, g, b, t);
        usleep(1000000 / 60);

        if (i != ds)
        {
            printAwan(x, y, p, q, 0, 0, 0, t);
        }
    }
}