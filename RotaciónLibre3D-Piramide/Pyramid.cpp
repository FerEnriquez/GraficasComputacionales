#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#include "Pyramid.h"
Pyramid::Pyramid(){
    point = 1.0;
    //A
    vertex[0][0] = 0.0;
    vertex[0][1] = 0.0;
    vertex[0][2] = 0.0;
    //B
    vertex[1][0] = point;
    vertex[1][1] = 0.0;
    vertex[1][2] = 0.0;
    //C
    vertex[2][0] = point;
    vertex[2][1] = 0.0;
    vertex[2][2] = point;
    //D
    vertex[3][0] = 0.0;
    vertex[3][1] = 0.0;
    vertex[3][2] = point;
    //H
    vertex[4][0] = point/2;
    vertex[4][1] = point;
    vertex[4][2] = point/2;
}
Pyramid::~Pyramid(){
    point = 0.0;
}
void Pyramid::printvertex(){
    int i = 0;
    for(i = 0; i < 5; i++){
        printf("%d :\n", i+1);
        printf("| %f |", vertex[i][0]);
        printf("| %f |", vertex[i][1]);
        printf("| %f |", vertex[i][2]);
        printf("\n");
    }
}
void Pyramid::draw(){
    glColor3f(1.0f,1.0f,1.0f);
    int i;
    for (i = 0; i < 3; i++){
        glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_LINES);
        glVertex3f(vertex[i][0],vertex[i][1],vertex[i][2]);
        glVertex3f(vertex[i+1][0],vertex[i+1][1],vertex[i+1][2]);
        glEnd();

    }
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);
    glVertex3f(vertex[3][0],vertex[3][1],vertex[3][2]);
    glVertex3f(vertex[0][0],vertex[0][1],vertex[0][2]);
    glEnd();



    for(i = 0; i < 4; i++){
        glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_LINES);
            glVertex3f(vertex[i][0],vertex[i][1],vertex[i][2]);
            glVertex3f(vertex[4][0], vertex[4][1], vertex[4][2]);
        glEnd();
    }
}
void Pyramid::Rotate(float d){
    int i = 0;
    for(i = 0; i < 5; i++){
//        printf(" BEFORE  %d\n", i+1);
//        printvertex();
        op.setPoints(1.0,1.0,1.0,0.0,2.5,-1.5);
        op.setAxis();
        mat.t(1.0,1.0,1.0);
        mat.RX(op.B() ,op.C() ,op.D());
        mat.RY(op.A(), op.D());
        mat.RZ(d);
        mat.InvRY(op.A(), op.D());
        mat.InvRX(op.B() ,op.C() ,op.D());
        mat.invT(1.0,1.0,1.0);
        mat.getPoints(vertex[i][0],vertex[i][1], vertex[i][2]);
        vertex[i][0] = mat.newX();
        vertex[i][1] = mat.newY();
        vertex[i][2] = mat.newZ();
        mat.clean();
//        printf("AFTER\n");
//        printvertex();
    }


}
