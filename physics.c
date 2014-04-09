#include "physics.h"
#include <math.h>
#include <stdlib.h>



Vector2 add(Vector2* a, Vector2* b) {
    Vector2 result = {a->x + b->x , a->y + b->y};
    return result;
}

Vector2 sub(Vector2* a, Vector2* b) {
    Vector2 result = {a->x - b->x, a->y - b->y};
    return result;
}

Vector2 mult(Vector2* a, int scalar) {
    Vector2 result = {scalar*a->x, scalar*a->y};
    return result;
}

/* Adds f to the applied forces of obj at index.
 *
 */
void addForce(Mover *obj, Vector2 *f, int index) {
    Vector2 sumF = add(&(obj->appliedForces[index]), f);
    (obj->appliedForces[index]) = sumF;
}

Vector2 randVector(int maxX, int maxY) {
    Vector2 v;
    srand(1);
    v.x = rand() % maxX;
    //srand();
    v.y = rand() % maxY;
    return v;
}

Point vec2point(Vector2 *v) {
    Point p = {HEIGHT - v->y, (v->x)};
    return p;
}

/*
PVector accumulator = PVector.mult(accel, timeStep*timeStep);
accumulator.add(pos);
accumulator.add(PVector.sub(pos, prePos));
return accumulator;
*/

//makes a force index zero
void clearForce(Mover *obj, int index) {
    Vector2 zeroVector = {0,0};
    (obj->appliedForces[index]) = zeroVector;
}
/*
float mag(Vector2 *v) {
    return sqrt(v->x * v-> x + v->y* v-> y);
}
*/
Vector2 divide(Vector2 *v, int scalar) {
    Vector2 result = {v->x / scalar, v->y / scalar};
    return result;
}

void updateMover(Mover *mov) {
    /*Vector2 sumF = sumForces(mov);
    Vector2 accel = divide(&sumF , mov->mass);
    Vector2 accumulator = mult(&accel, TIME_STEP*TIME_STEP);
    accumulator = add(&mov->pos, &accumulator);
    Vector2 deltaP = sub(&(mov->pos), &(mov->prePos));
    accumulator = add(&accumulator, &deltaP);
    mov->prePos = mov->pos;
    mov->pos = accumulator;*/ /*
    Vector2 movement = sub(&(mov->pos), &(mov->prePos));

    mov->pos = add(&(mov->pos), &movement);
    mov->pos.y = (mov->pos.y) % HEIGHT;
    mov->pos.x = (mov->pos.x) % WIDTH;
    */
    mov->prePos = mov->pos;
    mov->pos.y = ((mov->pos.y) + (rand() % 7 - 3)) % HEIGHT;
    mov->pos.x = ((mov->pos.x) + (rand() % 7 - 3)) % WIDTH;
}

Vector2 sumForces(Mover* mover) {
    Vector2 sumF;
    for(int i = 0; i < MAX_FORCE_AMOUNT; i++) {
        sumF = add(&sumF, &(mover->appliedForces[i]));
    }
    return sumF;
}

