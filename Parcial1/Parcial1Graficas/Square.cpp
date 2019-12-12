#include "Square.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

Square::Square(){
    float a, b;
    a = 50.0;
    b = 0.0;
    vertex[0][0] = b;
    vertex[0][1] = b;
    vertex[1][0] = a;
    vertex[1][1] = b;
    vertex[2][0] = a;
    vertex[2][1] = a;
    vertex[3][0] = b;
    vertex[3][1] = a;
    updatePoints();
}
Square::~Square(){
    pA.setValues(0,0);
    pB.setValues(0,0);
    pC.setValues(0,0);
    pD.setValues(0,0);
}
void Square::setVertex(float a, float b, float c, float d, float e, float f, float g, float h){
	pA.setValues(a,b);
    vertex[0][0] = a;
    vertex[0][1] = b;
    pB.setValues(c,d);
    vertex[1][0] = c;
    vertex[1][1] = d;
    pC.setValues(e,f);
    vertex[2][0] = e;
    vertex[2][1] = f;
    pD.setValues(g,h);
    vertex[3][0] = g;
    vertex[3][1] = h;
}
void Square::updatePoints(){
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

    a = vertex[3][0];
    b = vertex[3][1];
    pD.setValues(a,b);
}
void Square::printPoints(){
     int i;
     float a, b;
    for(i = 0; i < 4; i ++){
       a = vertex[i][0];
       printf("x - %f", a);
       b = vertex[i][1];
       printf(" y - %f \n", b);
    }
    printf(" --------------------\n");
}

void Square::draw(){
    Line ln1,ln2,ln3,ln4;
    ln1.setValues(pA, pB);
    ln2.setValues(pB, pC);
    ln3.setValues(pC, pD);
    ln4.setValues(pD, pA);
    ln1.draw();
    ln2.draw();
    ln3.draw();
    ln4.draw();
  //  printPoints();
}
void Square::opTras(float x, float y){
    int i;
    float a, b;
    mat.clean();
    for(i = 0; i < 4; i ++){
       a = vertex[i][0];
       b = vertex[i][1];
       mat.clean();
       mat.Pivote(a,b);
       mat.Move(x,y);
       mat.BackPivote(a,b);
       vertex[i][0] += mat.newPointX(x,y);
       vertex[i][1] += mat.newPointY();
       //printPoints();
    }
    updatePoints();
}
void Square::opEsc(float x, float y){
    int i;
    float a, b;
    mat.clean();
    for(i = 0; i < 4; i ++){
       a = vertex[i][0];
       b = vertex[i][1];
       //mat.Pivote(a,b);
       mat.Scale(x,y);
      // mat.BackPivote(a,b);
       vertex[i][0] += mat.newPointX(a,b);
       vertex[i][1] += mat.newPointY();
       mat.clean();
    }
    updatePoints();
}
void Square::opRot(float d, float x, float y){
    int i;
    float a, b;
    x = vertex[0][0];
    y = vertex[0][1];
    for(i = 0; i < 4; i ++){
       a = vertex[i][0];
       b = vertex[i][1];
       mat.clean();
       mat.Pivote(x,y);
       mat.Rotate(d);
       mat.BackPivote(x,y);
       //mat.printMat();
       vertex[i][0] = mat.newPointX(a,b);
       vertex[i][1] = mat.newPointY();
    }
    updatePoints();
}
