#include <windows.h>
#include <gl/gl.h>
#include <GL/glut.h>
#include <math.h>
#include "Pyramid.h"
float d = 0;
void draw(){
//    Pyramid px;
//    px.Rotate(d,1);
//    px.draw();
//    Pyramid py;
//    py.Rotate(d,2);
//    py.draw();
    Pyramid pz;
    pz.Rotate(d,1);
    pz.draw();
}
void drawAxis(){
    //X ROJO
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex3f(-3.0,0.0,0.0);
        glVertex3f(3.0,0.0,0.0);
    glEnd();
    //y VERDE
    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0,-3.0,0.0);
        glVertex3f(0.0,3.0,0.0);
    glEnd();
    //z AZUL
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_LINES);
        glVertex3f(0.0,0.0,-3.0);
        glVertex3f(0.0,0.0,3.0);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    draw();
    d+=10;
    if( d == 360){
        d = 0;
    }
    glFlush();
    Sleep(50);
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
