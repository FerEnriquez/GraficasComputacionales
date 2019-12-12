#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#include "Pyramid.h"
Pyramid::Pyramid(){
    edge = 1.0;
    h = 1.0;
    //A
    points[0][0] = 0.0;
    points[0][1] = 0.0;
    points[0][2] = 0.0;
    //B
    points[1][0] = edge;
    points[1][1] = 0.0;
    points[1][2] = 0.0;
    //C
    points[2][0] = edge;
    points[2][1] = 0.0;
    points[2][2] = edge;
    //D
    points[3][0] = 0.0;
    points[3][1] = 0.0;
    points[3][2] = edge;
    //H
    points[4][0] = edge/2;
    points[4][1] = h;
    points[4][2] = edge/2;
}
Pyramid::~Pyramid(){
    edge = 0.0;
}
void Pyramid::draw(float a, float b, float c){
    glColor3f(a,b,c);
    int i;
    for (i = 0; i < 3; i++){
        glBegin(GL_LINES);
        glVertex3f(points[i][0],points[i][1],points[i][2]);
        glVertex3f(points[i+1][0],points[i+1][1],points[i+1][2]);
        glEnd();

    }
    glBegin(GL_LINES);
    glVertex3f(points[3][0],points[3][1],points[3][2]);
    glVertex3f(points[0][0],points[0][1],points[0][2]);
    glEnd();

    for(i = 0; i < 4; i++){
        glBegin(GL_LINES);
            glVertex3f(points[i][0],points[i][1],points[i][2]);
            glVertex3f(points[4][0], points[4][1], points[4][2]);
        glEnd();
    }
}
void Pyramid::setPoint(float p){
    edge = p;
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
void Pyramid:: save(){
    op.save();
}
void Pyramid:: undo(){
    op.undo();
}
void Pyramid::Move(float a, float b, float c){
    float x,y,z;
    int i,j;
    float n = 0;
    float m = 0;
    float p = 0;
    for(i = 0; i < 3; i++){
        if(i == 0){
            n = a;
        } else if (i == 1){
            m = b;
        } else if (i == 2){
            p =  c;
        }
        for(j = 0; j < 5; j++){
            x = points[j][0];
            y = points[j][1];
            z = points[j][2];
            op.setPoint(x,y,z);
            op.Move(n,m,p);
            points[j][0] = op.newPointX();
            points[j][1] = op.newPointY();
            points[j][2] = op.newPointZ();
        }
        n = 0;
        m = 0;
        p = 0;
    }

}

void Pyramid::Scale(float a, float b, float c){
    float x,y,z;
    int i = 0;
    for(i = 0; i < 5; i++){
        x = points[i][0];
        y = points[i][1];
        z = points[i][2];
        op.setPoint(x,y,z);
        op.Scale(a,b,c);
        points[i][0] = op.newPointX();
        points[i][1] = op.newPointY();
        points[i][2] = op.newPointZ();
    }
}

void Pyramid::RotateAxis(float a, float b, float c){
    float x,y,z;
    int i = 0;
    for(i = 0; i < 5; i++){
        x = points[i][0];
        y = points[i][1];
        z = points[i][2];
        op.setPoint(x,y,z);
        op.RotateAxis(a,b,c);
        points[i][0] = op.newPointX();
        points[i][1] = op.newPointY();
        points[i][2] = op.newPointZ();
    }
}
void Pyramid::setPoints(float x1, float y1, float z1, float x2, float y2, float z2){
    op.setPoints( x1,  y1,  z1,  x2,  y2,  z2);
}
void Pyramid::RotateFree(float d){
    int i = 0;
    for(i = 0; i < 5; i++){
        op.setPoint(points[i][0],points[i][1], points[i][2]);
        op.RotateFree(d);
        points[i][0] = op.newPointX();
        points[i][1] = op.newPointY();
        points[i][2] = op.newPointZ();
    }
}


