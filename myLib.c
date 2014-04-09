#include "myLib.h"

static u16 *videoBuffer = (u16 *)0x6000000;

// A function to set pixel (r, c) to the color passed in.
void setPixel(int r, int c, u16 color) {
    *(videoBuffer + OFFSET(r, c, WIDTH)) = color;
}

// A function to draw a FILLED rectangle starting at (r, c)
void drawRect(int r, int c, int width, int height, u16 color) {
    for (int row = r; (row < HEIGHT) && (row < (height+r)); row++) {
            for (int col = c; (col < WIDTH) && (col < (width+c)); col++) {
                    setPixel(row, col, color);
                }
        }
}

// A function to draw a HOLLOW rectangle starting at (r, c)
void drawHollowRect(int r, int c, int width, int height, u16 color) {
    //left | and right
    for(int row = r; row < (height+r); row++) {
            setPixel(row, c, color);
            setPixel(row, c+width, color);
        }
    //top and bottom bars
    for(int col = c; col < (width+c+1); col++) {
            setPixel(r, col, color);
            setPixel(r+height, col, color);
        }
}

void waitForVblank() {
    while(SCANLINECOUNTER >160);
    while(SCANLINECOUNTER < 160);
}

void wait(int waitTime) {
    volatile int i;
    for(i = 0; i < waitTime; i++);
}

void fillScreen(volatile unsigned short color)
{
	DMA[3].src = &color;
	DMA[3].dst = videoBuffer;
	DMA[3].cnt = (160*240) | DMA_SOURCE_FIXED | DMA_ON;
}

