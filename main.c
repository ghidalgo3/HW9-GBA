#include <stdlib.h>
#include <stdio.h>

#include "myLib.h"
#include "text.h"
#include "physics.h"

#define STR_LENGTH 30
#define nObjects 5

Mover OBJS[nObjects];

static Vector2 g = {1,-1};

int score;
char message[STR_LENGTH];

struct cursor{
    int row;
    int col;
} cursor;

void initObjects() {
    for(int i = 0; i < nObjects; i++) {
        OBJS[i].pos = randVector(WIDTH, HEIGHT);
        OBJS[i].prePos = randVector(WIDTH, HEIGHT);
        //OBJS[i].mass = rand() % 10;
        OBJS[i].mass = 1;
        addForce(&OBJS[i], &g, GRAVITY );
    }
}

void drawCursor() {
    drawHollowRect(cursor.row, cursor.col, 10, 10, BLACK);
    if(KEY_DOWN_NOW(BUTTON_DOWN)) cursor.row+=3;
    if(KEY_DOWN_NOW(BUTTON_LEFT)) cursor.col-=3;
    if(KEY_DOWN_NOW(BUTTON_UP)) cursor.row-=3;
    if(KEY_DOWN_NOW(BUTTON_RIGHT)) cursor.col+=3;
    drawHollowRect(cursor.row, cursor.col, 10, 10, GREEN);
}

void updateObjects() {
    for(int i = 0; i < nObjects; i++) {
        wait(5000);
        //drawString(i*10, 0, message , BLACK);
        //sprintf(message, "Mov %d: <%d,%d>", i, OBJS[i].pos.x, OBJS[i].pos.x);
        //drawString(i*10, 0, message , YELLOW);
        Point pos = vec2point(&(OBJS[i].pos));
        Point prePos = vec2point(&(OBJS[i].prePos));
        drawHollowRect(prePos.row, prePos.col, 3,3,BLACK);
        drawHollowRect(pos.row, pos.col, 3,3,YELLOW);
        updateMover(&OBJS[i]);
    }
    //drawString(150,10,"update called", BLUE);
}

int cursorIsColliding(Mover *m) {
    Point moverPoint = vec2point(&m->pos);
    if((moverPoint.col - cursor.col) < 10 && (moverPoint.row - cursor.row) < 10
        && (moverPoint.col - cursor.col) >= 0 && (moverPoint.row - cursor.row) >= 0) return 1;
    return 0;
}

void checkCollisions() {
    for(int i = 0; i < nObjects; i++) {
        if(cursorIsColliding(&OBJS[i])) {
            score++;
        }
    }
}

void displayScore() {
    drawString(0,0,message, BLACK);
    sprintf(message, "Score: %d", score);
    drawString(0,0,message, BLUE);
}

void youWin() {
    char win[9];
    sprintf(win, "You win!");
    drawString(60,60,win, BLUE);
}

int main() {
    srand(1001);
    REG_DISPCTL = MODE3 | BG2_ENABLE;
    //char message[STR_LENGTH];
    initObjects();
    while(1) {
        waitForVblank();
        drawCursor();
        updateObjects();
        checkCollisions();
        displayScore();
        if(score >= 50) {
            youWin();
        }
    }
    return 0;
}








