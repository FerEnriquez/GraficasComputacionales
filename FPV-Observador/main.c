/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//Variables dimensiones de la pantalla
int WIDTH=500;
int HEIGTH=500;
//Variables para establecer los valores de gluPerspective
float FOVY=60.0;
float ZNEAR=0.01;
float ZFAR=100.0;
//Variables para definir la posicion del observador
//Por default se inicializa en (0,0,0) y mirando hacia x positivo
//gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z)
float EYE_X=0.0;
float EYE_Y=0.0;
float EYE_Z=0.0;
float CENTER_X=1;
float CENTER_Y=0;
float CENTER_Z=0;
float UP_X=0;
float UP_Y=1;
float UP_Z=0;
//Variables para dibujar los ejes del sistema
float X_MIN=-50;
float X_MAX=50;
float Y_MIN=-50;
float Y_MAX=50;
float Z_MIN=-50;
float Z_MAX=50;
//Variables para matrices de rotacion y traslación
float Theta=0;
//float Radio=1.0;
float PI = 3.14159265359;
float Direction[3] = {1.0,0.0,0.0};

//Recordar que (pi/180 = r/g) donde "r" son radianes y "g" grados
//Se aplica la formula r
float RadToDeg(float r)
{
      return ((180.0*r)/PI);
}

float DegToRad(float g)
{
      return ((g*PI)/180.0);
}

void drawAxis()
{
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

void drawCubes(void)
{
    glPushMatrix();
    glTranslated(10,0,0);
    glColor3f(1.0,0.0,1.0);
    glutSolidCube(1);
    glTranslated(-20,0,0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,10,0);
    glColor3f(0.0,1.0,0.0);
    glutSolidCube(1);
    glTranslated(0,-20,0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,0,10);
    glColor3f(0.0,0.0,1.0);
    glutSolidCube(1);
    glTranslated(0,0,-20);
    glutSolidCube(1);
    glPopMatrix();

}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGTH, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
    glClearColor(0,0,0,0);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_FLAT);
}

void LookAt()
{
    Direction[0] = cos(DegToRad(Theta));
    Direction[2] = sin(DegToRad(Theta));
    CENTER_X = EYE_X + Direction[0];
    CENTER_Z = EYE_Z + Direction[2];
}

void SpecialInput(int key, int x, int y)
{
    switch(key){
                case GLUT_KEY_UP:
                     EYE_X += Direction[0];
                     EYE_Y += Direction[1];
                     EYE_Z += Direction[2];
                     CENTER_X = EYE_X + Direction[0];
                     CENTER_Y = EYE_Y + Direction[1];
                     CENTER_Z = EYE_Z + Direction[2];
                     break;
                case GLUT_KEY_DOWN:
                     EYE_X -= Direction[0];
                     EYE_Y -= Direction[1];
                     EYE_Z -= Direction[2];
                     CENTER_X = EYE_X + Direction[0];
                     CENTER_Y = EYE_Y + Direction[1];
                     CENTER_Z = EYE_Z + Direction[2];
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

//--------------------------------------------------------------------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    drawCubes();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGTH);
    glutCreateWindow("Triangulo a color");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutSpecialFunc(SpecialInput);
    glutMainLoop();
    return 0;
}
