#include <windows.h>
#include <gl/gl.h>
#include <GL/glut.h>
#include <math.h>
#include "Ship.h"
#include "Star.h"
float d = 0;
float x = -10;
void draw(){
    Star s1;
    s1.Scale(0.3,0.3,0.3);
    s1.setAxis(2.0,2.0,0.0,0.0,0.0,2.0);
    s1.RotateFree(d);
    s1.Move(0.0,x,0.0);
    s1.draw();
    //s1.undo();
    //s1.draw();

    Star s11;
    s11.Scale(0.3,0.3,0.3);
    s11.setAxis(2.0,2.0,0.0,0.0,0.0,2.0);
    s11.RotateFree(d);
    s11.draw();

    Star s2;
    s2.Move(5.0,-5.0,0.0);
    s2.Scale(0.5,0.5,0.5);
    s2.RotateAxis(-d,0.0,0.0);
    s2.draw();

    Star s3;
    s3.Move(-3.0,0.0,-5.0);
    s3.Scale(0.5,0.5,0.5);
    s3.setAxis(2.0,2.0,0.0,0.0,0.0,2.0);
    s3.RotateFree(d);

    s3.draw();

    Star s4;
    s4.Move(-2.0,3.0,2.0);
    s4.Move(x,x,0.0);
    s4.draw();

    Star s5;
    s5.Scale(0.4,0.4,0.4);
    s5.Move(x,-1.0,2.0);
    s5.RotateAxis(0.0,0.0,d);
    s5.draw();


    Ship sh;
    sh.Move(-x,0.0,0.0);
    sh.RotateAxis(d,0.0,0.0);
    sh.draw();
}
void drawAxis(){
    //X ROJO
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex3f(-3.0,0.0,0.0);
        glVertex3f(3.0,0.0,0.0);
    glEnd();
    //Y VERDE
    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0,-3.0,0.0);
        glVertex3f(0.0,3.0,0.0);
    glEnd();
    //Z AZUL
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0,0.0,-3.0);
        glVertex3f(0.0,0.0,3.0);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    //drawAxis();
    draw();
    //Degree
    d+=10;
    if( d == 360){
        d = 0;
    }
    //Move
    x=x+0.5;
    if( x == 10){
        x = -10;
    }


    glFlush();
    Sleep(100);
}

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4,4,-4,4,-4,4);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1,1,1,0,0,0,0,1,0); //Posicion del observador, el lente de una camara
    //1,1,1, donde se ubica
    //0,0,0, punto al sistema al que mira
    //0,-1,0, es un vector como un angulo para observa -1 esta de cabeza, al reves
    glClearColor(0,0,0,0);
}

int main(int argc, char** argv) //Se repite una vez y se queda en un loop  *FLUSH libera a la pantalla
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(50,50); /* coloca la ventana de despliegue en esq. sup. izq */
    glutInitWindowSize(500,500); /* ventana 500x500 pixeles */
    glutCreateWindow("Ejes"); /* título de la ventana*/
    init(); /* fija o establece los atributos */
    glutDisplayFunc(display); /*llama a la funcion display cuando se abre la ventana */
    //While infinitp
    glutIdleFunc(display);//Mientras el usuario no haga nada va seguir dibujando una pantalla 24 veces x seg
    glutMainLoop(); /* entra a un ciclo de evento */
    return 0;
}
