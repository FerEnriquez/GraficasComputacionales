#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#include "Pyramid.h"

Pyramid::Pyramid(){
    point = 2.0;
    h = 2.0;
    //A
    points[0][0] = 0.0;
    points[0][1] = 0.0;
    points[0][2] = 0.0;
    //B
    points[1][0] = point;
    points[1][1] = 0.0;
    points[1][2] = 0.0;
    //C
    points[2][0] = point;
    points[2][1] = 0.0;
    points[2][2] = point;
    //D
    points[3][0] = 0.0;
    points[3][1] = 0.0;
    points[3][2] = point;
    //H
    points[4][0] = point/2;
    points[4][1] = h;
    points[4][2] = point/2;
}
Pyramid::~Pyramid(){
    point = 0.0;
}
void Pyramid::setPoint(float x){
    point = x;
}
void Pyramid::setAltura(float x){
    h = x;
}
void Pyramid::printPoints(){
    int i = 0;
    for(i = 0; i < 5; i++){
        printf("| %f |", points[i][0]);
        printf("| %f |", points[i][1]);
        printf("| %f |", points[i][2]);
        printf("\n");
    }
}
void Pyramid::draw(){
    glColor3f(1.0f,1.0f,1.0f);
    int i;
    for (i = 0; i < 3; i++){
        glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_LINES);
        glVertex3f(points[i][0],points[i][1],points[i][2]);
        glVertex3f(points[i+1][0],points[i+1][1],points[i+1][2]);
        glEnd();

    }
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);
    glVertex3f(points[3][0],points[3][1],points[3][2]);
    glVertex3f(points[0][0],points[0][1],points[0][2]);
    glEnd();



    for(i = 0; i < 4; i++){
        glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_LINES);
            glVertex3f(points[i][0],points[i][1],points[i][2]);
            glVertex3f(points[4][0], points[4][1], points[4][2]);
        glEnd();
    }
}
void Pyramid::Rotate(float d, int cond){
    int i = 0;
    for(i = 0; i < 5; i++){
        float a = points[i][0];
        float b = points[i][1];
        float c = points[i][2];
        //printf(" BEFORE  %d\n", i+1);
        //printPoints();
        mat.setPoint(a,b,c);
        if(cond == 1){
            mat.RotateX(d);
        }
        else if(cond == 2){
            mat.RotateY(d);
        }
        else{
            mat.RotateZ(d);
        }
        points[i][0] = mat.newPointX();
        points[i][1] = mat.newPointY();
        points[i][2] = mat.newPointZ();
        //printf("AFTER\n");
        //printPoints();
        mat.clean();
    }
}
