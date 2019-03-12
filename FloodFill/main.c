/* Tugas 5 - Flood Fill. */

#include "framebuffer.h"
#include "shape.h"

int main() {
	initFbp();

	printBangunan(625, 285, 0.875, 255, 141, 53, 0);
	printBulanSabit(950, 100, 50, 255, 255, 0, 0);
	printTank(400, 500, 25, 0, 100, 0, 0);
	printBullet(500, 470, 5, 4, 143, 188, 143, 0);
	printPesawat(475, 160, 0.75, 0, 0, 139, 0);
	printRudal(400, 225, 1, 3, 95, 158, 160, 0);

	closeFbp();
	return 0;
}