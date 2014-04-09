#include "myLib.h"

#define MAX_FORCE_AMOUNT 10
#define GRAVITY 0
#define FORCE_ONE 1
#define FORCE_TWO 2
#define FORCE_THREE 3
#define TIME_STEP 3

typedef struct Vector2 {
    u16 x;
    u16 y;
} Vector2;

//indices of appliedForces are special
typedef struct Mover{
    Vector2 pos;
    Vector2 prePos;
    int mass;
    Vector2 appliedForces[MAX_FORCE_AMOUNT];
} Mover;

Vector2 randVector(int maxX, int maxY);
Vector2 add(Vector2 *a, Vector2 *b);
Vector2 mult(Vector2 *a, int scalar);
Vector2 sub(Vector2 *a, Vector2 *b);
void addForce(Mover *obj, Vector2 *f, int index);
void clearForce(Mover *obj, int index);
Point vec2point(Vector2 *v);
void updateMover(Mover *mov);
Vector2 sumForces(Mover* mover);
Vector2 divide(Vector2 *v, int scalar);
//float mag(Vector2 *v);



