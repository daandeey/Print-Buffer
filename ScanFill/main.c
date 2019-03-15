/* Tugas 6 - Scan Fill. */

#include "framebuffer.c"
#include "shape.c"

int main() {
	initFbp();

	printLingkaran(250, 250, 100, 255, 255, 255, 0);
	scanLineFill(255, 255, 255, 0, 255, 0, 0, 0);

	closeFbp();
	return 0;
}