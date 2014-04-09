#ifndef MYLIB_H
#define MYLIB_H
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Point
{
        u16 row;
        u16 col;
} Point;


#define REG_DISPCTL *(u16 *)0x4000000
#define MODE3 3
#define MODE7 7
#define BG2_ENABLE (1<<10)
#define RGB(r,g,b) ((r) | (g) << 5 | (b) << 10)
#define RED RGB(31,0,0)
#define WHITE RGB(31,31,31)
#define BLACK 0
#define YELLOW RGB(31,31,0)
#define MAGENTA RGB(31,0,31)
#define BLUE RGB(0,0,31)
#define CYAN RGB(0,31,31)
#define GREEN RGB(0,31,0)
#define GREY RGB(15,15,15)
#define OFFSET(r,c, numcols) ((r)*numcols+(c))
#define SCANLINECOUNTER  *(volatile unsigned short *)0x4000006

#define HEIGHT 160
#define WIDTH 240
#define BUTTONS *(volatile unsigned int *)0x4000130
#define BUTTON_A		(1<<0)
#define BUTTON_B		(1<<1)
#define BUTTON_SELECT   (1<<2)
#define BUTTON_START	(1<<3)
#define BUTTON_RIGHT	(1<<4)
#define BUTTON_LEFT		(1<<5)
#define BUTTON_UP		(1<<6)
#define BUTTON_DOWN		(1<<7)
#define BUTTON_R		(1<<8)
#define BUTTON_L		(1<<9)
#define KEY_DOWN_NOW(key)  (~(BUTTONS) & key)

/* DMA */

typedef struct
{					// ***********************************************************
	 const volatile void *src;	// We mark this as const which means we can assign it const
	 volatile void *dst;		// things without the compiler yelling but we can also pass it
	 volatile u32 cnt;		// things that are not const!
					// ***********************************************************
} DMAREC;

#define DMA ((volatile DMAREC *)0x040000B0)

#define DMA_DESTINATION_INCREMENT (0 << 21)
#define DMA_DESTINATION_DECREMENT (1 << 21)
#define DMA_DESTINATION_FIXED (2 << 21)
#define DMA_DESTINATION_RESET (3 << 21)

#define DMA_SOURCE_INCREMENT (0 << 23)
#define DMA_SOURCE_DECREMENT (1 << 23)
#define DMA_SOURCE_FIXED (2 << 23)

#define DMA_REPEAT (1 << 25)

#define DMA_16 (0 << 26)
#define DMA_32 (1 << 26)

#define DMA_NOW (0 << 28)
#define DMA_AT_VBLANK (1 << 28)
#define DMA_AT_HBLANK (2 << 28)
#define DMA_AT_REFRESH (3 << 28)

#define DMA_IRQ (1 << 30)
#define DMA_ON (1 << 31)

#define START_ON_FIFO_EMPTY 0x30000000

void setPixel(int r, int c, u16 color);
void drawRect(int r ,int c, int width, int height, u16 color);
void drawHollowRect(int r ,int c, int width, int height, u16 color);
void waitForVblank();
void wait(int waitTime);
void fillScreen(volatile unsigned short color);

#endif
