#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include "Asteroid.h"

Asteroid::Asteroid(){
    p  = 1.0;
}
Asteroid::~Asteroid(){
}
void Asteroid::setHeight(float h){
    p = h;
}
void Asteroid::drawTexture(){
///*1*/
    glColor3f(0.647059,0.164706,0.164706);
	glBegin(GL_TRIANGLES);
		glVertex3f(p,p,p);
		glVertex3f(p,0,p);
		glVertex3f(2*p,p/2,p/2);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(p,p,p);
		glVertex3f(p,p,0);
		glVertex3f(2*p,p/2,p/2);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(p,0,0);
		glVertex3f(p,p,0);
		glVertex3f(2*p,p/2,p/2);
	glEnd();
	glBegin(GL_TRIANGLES);
        glVertex3f(p,0,p);
		glVertex3f(p,p,0);
		glVertex3f(2*p,p/2,p/2);
	glEnd();
///*2*/

	glBegin(GL_TRIANGLES);
		glVertex3f(0,0,p);
		glVertex3f(p,0,p);
		glVertex3f(p/2,-2*p,p/2);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(0,0,0);
		glVertex3f(0,0,p);
		glVertex3f(p/2,-2*p,p/2);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(0,0,0);
		glVertex3f(p,0,0);
		glVertex3f(p/2,-2*p,p/2);
	glEnd();
	glBegin(GL_TRIANGLES);
        glVertex3f(p,0,0);
		glVertex3f(p,0,p);
		glVertex3f(p/2,-2*p,p/2);
	glEnd();
///*3*/
	glBegin(GL_TRIANGLES);
		glVertex3f(0,p,p);
		glVertex3f(0,p,0);
		glVertex3f(-2*p,p/2,p/2);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(0,p,0);
		glVertex3f(0,0,0);
		glVertex3f(-2*p,p/2,p/2);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(0,0,0);
		glVertex3f(0,0,p);
		glVertex3f(-2*p,p/2,p/2);
	glEnd();
	glBegin(GL_TRIANGLES);
        glVertex3f(0,0,p);
		glVertex3f(0,p,p);
		glVertex3f(-2*p,p/2,p/2);
	glEnd();
///*4*/
	glBegin(GL_TRIANGLES);
		glVertex3f(0,p,0);
		glVertex3f(p,p,0);
		glVertex3f(p/2,2*p,p/2);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(p,p,0);
		glVertex3f(p,p,p);
		glVertex3f(p/2,2*p,p/2);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(p,p,p);
		glVertex3f(0,p,p);
		glVertex3f(p/2,2*p,p/2);
	glEnd();
	glBegin(GL_TRIANGLES);
        glVertex3f(0,p,p);
		glVertex3f(p,0,p);
		glVertex3f(p/2,2*p,p/2);
	glEnd();
///*5*/
	glBegin(GL_TRIANGLES);
		glVertex3f(0,p,p);
		glVertex3f(0,0,p);
		glVertex3f(p/2,p/2,2*p);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(0,0,p);
		glVertex3f(0,p,p);
		glVertex3f(p/2,p/2,2*p);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(0,p,p);
		glVertex3f(p,p,p);
		glVertex3f(p/2,p/2,2*p);
	glEnd();
	glBegin(GL_TRIANGLES);
        glVertex3f(p,p,p);
		glVertex3f(0,p,p);
		glVertex3f(p/2,p/2,2*p);
	glEnd();
///*6*/
	glBegin(GL_TRIANGLES);
		glVertex3f(0,p,0);
		glVertex3f(p,p,0);
		glVertex3f(p/2,p/2,2*p);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(p,p,0);
		glVertex3f(p,0,0);
		glVertex3f(p/2,p/2,2*p);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(p,0,0);
		glVertex3f(0,0,0);
		glVertex3f(p/2,p/2,2*p);
	glEnd();
	glBegin(GL_TRIANGLES);
        glVertex3f(0,0,0);
		glVertex3f(0,p,0);
		glVertex3f(p/2,p/2,2*p);
	glEnd();
}

void Asteroid::drawInterpolated(){
    float vertexCoords[42] = {
        0,p,p,  0,p,0,  p,p,0,  p,p,p,
        0,0,0,  p,0,0,  p,0,p,  0,0,p,
        -2*p,p/2,p/2,   p/2,2*p,p/2,    2*p,p/2,p/2,    p/2,-2*p,p/2,
         p/2,p/2,2*p,  p/2,p/2,-2*p,};
    float vertexColors[42] = {
        0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,
        0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,
        1,1,1,   1,1,1,   1,1,1,   1,1,1,
        1,1,1,   1,1,1 };
    int elementArray[72] = {
        0,1,9,  1,2,9,  2,3,9,  3,0,9,
        2,3,10, 3,6,10, 6,5,10, 5,2,10,
        4,7,11, 7,6,11, 6,5,11, 5,4,11,
        0,1,8,  1,4,8,  4,7,8,  7,0,8,
        0,3,12, 3,6,12, 6,7,12, 7,0,12,
        1,2,13,  2,5,13,  5,4,13, 4,1,13
};

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertexCoords);
    glColorPointer(3, GL_FLOAT, 0, vertexColors);

    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(1,1);
    glDrawElements(GL_TRIANGLES,72,GL_UNSIGNED_INT,elementArray);
    glDisable(GL_POLYGON_OFFSET_FILL);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}
void Asteroid::drawSolid(){
    float vertexCoords[42] = {
        0,p,p,  0,p,0,  p,p,0,  p,p,p,
        0,0,0,  p,0,0,  p,0,p,  0,0,p,
        -2*p,p/2,p/2,   p/2,2*p,p/2,    2*p,p/2,p/2,    p/2,-2*p,p/2,
         p/2,p/2,2*p,  p/2,p/2,-2*p,};
    float vertexColors[42] = {
        0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,
        0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,
        0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,
        0.647059,0.164706,0.164706,   0.647059,0.164706,0.164706,};
    int elementArray[72] = {
        0,1,9,  1,2,9,  2,3,9,  3,0,9,
        2,3,10, 3,6,10, 6,5,10, 5,2,10,
        4,7,11, 7,6,11, 6,5,11, 5,4,11,
        0,1,8,  1,4,8,  4,7,8,  7,0,8,
        0,3,12, 3,6,12, 6,7,12, 7,0,12,
        1,2,13,  2,5,13,  5,4,13, 4,1,13
};

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertexCoords);
    glColorPointer(3, GL_FLOAT, 0, vertexColors);

    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(1,1);
    glDrawElements(GL_TRIANGLES,72,GL_UNSIGNED_INT,elementArray);
    glDisable(GL_POLYGON_OFFSET_FILL);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}
void Asteroid::draw(int cond){
    if(cond == 1){
        drawTexture();
    } else if(cond == 2){
        drawInterpolated();
    } else if(cond == 3){
        drawSolid();
    }
}
void Asteroid::Move(int type, float x, float y, float z){
    glPushMatrix();
    glTranslatef(x,y,z);
    draw(type);
    glPopMatrix();
}
void Asteroid::Scale(int type, float x, float y, float z){
    glPushMatrix();
    glScalef(x,y,z);
    draw(type);
    glPopMatrix();
}
void Asteroid::RotateAxis(int type, float d, float x, float y, float z){
    glPushMatrix();
    glRotatef(d,x,y,z);
    draw(type);
    glPopMatrix();
}





