#include "Triangle.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

Triangle::Triangle(){
    pA.setValues(0,0);
    pB.setValues(10,20);
    pC.setValues(0,20);
}

Triangle::~Triangle(){
    pA.setValues(0,0);
    pB.setValues(0,0);
    pC.setValues(0,0);
}

void Triangle::setVertex(float a, float b, float c, float d, float e, float f){
    pA.setValues(a,b);
    vertex[0][0] = a;
    vertex[0][1] = b;
    pB.setValues(c,d);
    vertex[1][0] = c;
    vertex[1][1] = d;
    pC.setValues(e,f);
    vertex[2][0] = e;
    vertex[2][1] = f;
}
void Triangle::updatePoints(){
    float a, b;
    a = vertex[0][0];
    b = vertex[0][1];
    pA.setValues(a,b);

    a = vertex[1][0];
    b = vertex[1][1];
    pB.setValues(a,b);

    a = vertex[2][0];
    b = vertex[2][1];
    pC.setValues(a,b);
}
void Triangle::printPoints(){
     int i;
     float a, b;
    for(i = 0; i < 3; i ++){
       a = vertex[i][0];
       printf("x - %f", a);
       b = vertex[i][1];
       printf(" y - %f \n", b);
    }
    printf(" --------------------\n");
}
void Triangle::draw(){
    Line ln1,ln2,ln3;
    ln1.setValues(pA, pB);
    ln2.setValues(pB, pC);
    ln3.setValues(pC, pA);
    ln1.draw();
    ln2.draw();
    ln3.draw();
    //printPoints();
}
void Triangle::opTras(float x, float y){
    int i;
    float a, b;
    mat.clean();
    for(i = 0; i < 3; i ++){
       a = vertex[i][0];
       b = vertex[i][1];
       mat.Pivote(a,b);
       mat.Move(x,y);
       mat.BackPivote(a,b);
       vertex[i][0] += mat.newPointX(x,y);
       vertex[i][1] += mat.newPointY();
    }
    updatePoints();
}
void Triangle::opEsc(float x, float y){
    int i;
    float a, b;
    mat.clean();
    for(i = 0; i < 3; i ++){
       a = vertex[i][0];
       b = vertex[i][1];
       //mat.Pivote(a,b);
       mat.Scale(x,y);
       //mat.BackPivote(a,b);
      // mat.printMat();
       vertex[i][0] = mat.newPointX(a,b);
       //printf("x - %f\n", vertex[i][0] );
       vertex[i][1] = mat.newPointY();
       //printf("y - %f\n", vertex[i][1] );
       mat.clean();
    }
    updatePoints();
}
void Triangle::opRot(float d, float x, float y){
    int i;
    float a, b;
    mat.clean();
    x = vertex[0][0];
    y = vertex[0][1];
   // printPoints();
    for(i = 0; i < 3; i ++){
       a = vertex[i][0];
       b = vertex[i][1];
       mat.Pivote(x,y);
       mat.Rotate(d);
       mat.BackPivote(x,y);
       //mat.printMat();
       vertex[i][0] = mat.newPointX(a,b);
       vertex[i][1] = mat.newPointY();
       mat.clean();
     //  printPoints();
    }
    updatePoints();
}
