#include <GL/glut.h>
#include <GL/glext.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "SolarSystem.h"
int WIDTH=500;
int HEIGTH=500;
float FOVY=60.0;
float ZNEAR=0.01;
float ZFAR=100.0;
float EYE_X=5.0;
float EYE_Y=5.0;
float EYE_Z=5.0;
float CENTER_X=0;
float CENTER_Y=0;
float CENTER_Z=0;
float UP_X=0;
float UP_Y=1;
float UP_Z=0;
float X_MIN=-50;
float X_MAX=50;
float Y_MIN=-50;
float Y_MAX=50;
float Z_MIN=-50;
float Z_MAX=50;
float Theta=0;
float PI = 3.14159265359;
float Direction[3] = {1.0,0.0,0.0};
float points[5][3]={{0,0,1},{1,0,1},{1,0,0},{0,0,0},{0.5,1.0,0.5}};
float d,x,z,y;


void drawSpace(){
    SolarSystem s;
    s.drawAsteriods(d,x,y,z);
    s.drawPlanets(d,x,y,z);
}

float RadToDeg(float r){
      return ((180.0*r)/PI);
}

float DegToRad(float g){
      return ((g*PI)/180.0);
}
void drawAxis(){
     //X axis in red
     glBegin(GL_LINES);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex3f(X_MIN,0.0,0.0);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex3f(X_MAX,0.0,0.0);
     glEnd();
     //Y axis in green
     glBegin(GL_LINES);
       glColor3f(0.0f,1.0f,0.0f);
       glVertex3f(0.0,Y_MIN,0.0);
       glColor3f(0.0f,1.0f,0.0f);
       glVertex3f(0.0,Y_MAX,0.0);
     glEnd();
     //Z axis in blue
     glBegin(GL_LINES);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3f(0.0,0.0,Z_MIN);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3f(0.0,0.0,Z_MAX);
     glEnd();
 }

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGTH, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
}


void LookAt(){
    Direction[0] = cos(DegToRad(Theta));
    Direction[2] = sin(DegToRad(Theta));
    Direction[1] = tan(DegToRad(Theta));
    CENTER_X = EYE_X + Direction[0];
    CENTER_Z = EYE_Z + Direction[2];
    CENTER_Y = EYE_Y + Direction[1];
}
void NormalKeyHandler (unsigned char key, int x, int y){
    switch(key){
                case 'w':
                     EYE_X += Direction[0];
                     EYE_Y += Direction[1];
                     EYE_Z += Direction[2];
                     CENTER_X = EYE_X + Direction[0];
                     CENTER_Y = EYE_Y + Direction[1];
                     CENTER_Z = EYE_Z + Direction[2];
                     break;
                case 's':
                     EYE_X -= Direction[0];
                     EYE_Y -= Direction[1];
                     EYE_Z -= Direction[2];
                     CENTER_X = EYE_X + Direction[0];
                     CENTER_Y = EYE_Y + Direction[1];
                     CENTER_Z = EYE_Z + Direction[2];
                     break;
                case 'a':
                     Theta -= 1.0f;
                     Theta = (Theta < 0.0) ? 359.0 : Theta;
                     LookAt();
                      break;
                case 'd':
                     Theta += 1.0f;
                     Theta = (Theta > 359.0) ? 0.0 : Theta;
                     LookAt();
                     break;
    }
    glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
    glutPostRedisplay();
}
void SpecialInput(int key, int x, int y){
    switch(key){
                case GLUT_KEY_UP:
                     EYE_Y += Direction[1];
                     CENTER_Y = EYE_Y + Direction[1];
                     break;
                case GLUT_KEY_DOWN:
                     EYE_Y -= Direction[1];
                     CENTER_Y = EYE_Y + Direction[1];
                     break;
                case GLUT_KEY_LEFT:
                     Theta -= 1.0f;
                     Theta = (Theta < 0.0) ? 359.0 : Theta;
                     LookAt();
                      break;
                case GLUT_KEY_RIGHT:
                     Theta += 1.0f;
                     Theta = (Theta > 359.0) ? 0.0 : Theta;
                     LookAt();
                     break;
    }
    glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
    glutPostRedisplay();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawAxis();

    drawSpace();
    d = 0;
    y = 0;
    z = 0;
    x += 0.01;

    if(x == 10){
        x = 0;
    }

    glFlush();
    //Sleep(100);
    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("FINAL | Space");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutSpecialFunc(SpecialInput);
    glutKeyboardFunc(NormalKeyHandler);
    glutMainLoop();
    return 0;
}
