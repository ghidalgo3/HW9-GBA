#include "myLib.h"
#include "text.h"

void drawChar(int row, int col, unsigned char ch, unsigned short color)
{
	int r,c;
	for(r=0; r<8; r++)
	{
		for(c=0; c<6; c++)
		{
			if(fontdata_6x8[OFFSET(r, c, 6) + ch*48])
			{
				setPixel(r+row, c+col, color);
			}
		}
	}
}

void drawString(int row, int col, char* ch, u16 color) {
    int charOffset = 0;
    while(*ch) {
        drawChar(row, col+charOffset, *ch, color);
        ch++;
        charOffset+=6;
    }
}
