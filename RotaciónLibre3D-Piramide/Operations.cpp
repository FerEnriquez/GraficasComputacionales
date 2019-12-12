#include "Operations.h"
#include <stdio.h>
#include <math.h>
#define PI 3.14159265
Operations::Operations(){
}
Operations::~Operations(){
}
void Operations:: setGrados(float g){
    grados = g;
}
void Operations::setPoints(float x1, float y1, float z1, float x2, float y2, float z2){
    pA[0] = x1;
    pA[1] = y1;
    pA[2] = z1;
    pB[0] = x2;
    pB[1] = y2;
    pB[2] = z2;
}
void Operations::setAxis(){
    float a1 = pB[0] - pA[0];
    float b1 = pB[1] - pA[1];
    float c1 = pB[2] - pA[2];
    a1 = a1*a1;
    b1 = b1*b1;
    c1 = c1*c1;
    float v = a1 + b1 + c1;
    v = sqrt(v);
    a = (pB[0] - pA[0]) / v;
    b = (pB[1] - pA[1]) / v;
    c = (pB[2] - pA[2]) / v;
    d = (b*b) + (c*c);
    d = sqrt(d);
    //printf(" V = %f\n", d);
}
float Operations:: A(){
    return a;
}
float Operations:: B(){
    return b;
}
float Operations:: C(){
    return c;
}
float Operations:: D(){
    return d;
}
