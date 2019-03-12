#include <linux/fb.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1280

int fbfd;					// Framebuffer
char *fbp;					// Framebuffer pointer
struct fb_var_screeninfo vinfo;	// Variable screen information
struct fb_fix_screeninfo finfo;	// Fixed screen information
long int screensize;		// Screensize

// Initialize framebuffer
void initFbp();

// Close framebuffer
void closeFbp();

// Set pixel in location x and y with color r, g, b and t
void fillPixel(int x, int y, int r, int g, int b, int t);

// Flood fill pixel in location x and y with color r, g, b and t
void floodFillPixel(int x, int y, int r0, int g0, int b0, int t0, int r1, int g1, int b1, int t1);

// Clear Background
void clearBackground();

#endif