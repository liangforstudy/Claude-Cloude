#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>

//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------

	// the vblank interrupt must be enabled for VBlankIntrWait() to work
	irqInit();
	irqEnable(IRQ_VBLANK);

	// sets up the text console on background 0 (BG0)
	consoleDemoInit();

	// ansi escape sequence to set print co-ordinates
	// /x1b[line;columnH
	iprintf("\x1b[10;9HHello World!\n");

	// how far the text has been moved from where it was printed, in pixels
	int x = 0;
	int y = 0;

	while (1) {
		VBlankIntrWait();

		scanKeys();
		u16 held = keysHeld();

		if (held & KEY_LEFT)  x--;
		if (held & KEY_RIGHT) x++;
		if (held & KEY_UP)    y--;
		if (held & KEY_DOWN)  y++;

		// The scroll registers move the "camera" over the background, so the
		// background itself appears to move the opposite way. Negate them so
		// pressing right moves the text right.
		REG_BG0HOFS = -x;
		REG_BG0VOFS = -y;
	}
}
