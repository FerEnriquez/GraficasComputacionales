#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
float x = 0;
float y = 0;
float a = 250;
float b = 250;
float d = 0;
float e = 0;

void dibujaTriangulo(){
    //Traslada derecha
    Triangle t1;
    t1.setVertex(0,0,10,17.3205,20,0);
    t1.opTras(x,0);
    t1.draw();
    //Traslada izquierda
    Triangle t2;
    t2.setVertex(0,0,10,17.3205,20,0);
    t2.opTras(a,0);
    t2.draw();
    //Traslada derecha arriba
    Triangle t3;
    t3.setVertex(0,0,10,17.3205,20,0);
    t3.opTras(125,0);
    t3.opTras(0,y);
    t3.draw();
    //Traslada izquierda arriba
    Triangle t4;
    t4.setVertex(0,0,10,17.3205,20,0);
    t4.opTras(125,0);
    t4.opTras(0,b);
    t4.draw();
    //Rota
    Triangle t5;
    t5.setVertex(0,0,20,34.7,40,0);
    t5.opTras(100,0);
    t5.opTras(0,b);
    t5.opRot(d ,0 ,0 );
    t5.draw();
    Triangle t7;
    t7.setVertex(0,0,20,34.7,40,0);
    t7.opTras(100,0);
    t7.opTras(0,y);
    t7.opRot(d ,0 ,0 );
    t7.draw();
    //Escala
    Triangle t6;
    t6.setVertex(0,0,20,34.7,40,0);
    t6.opTras(0,0);
    t6.opEsc(e,e);
    t6.draw();
}
void dibujaCirculo(){

    Circle c1;
    c1.setRadio(10);
    c1.setCenter(10,0);
    c1.opTras(0,y);
    c1.draw();

    Circle c2;
    c2.setRadio(10);
    c2.setCenter(10,0);
    c2.opTras(240,y);
    c2.draw();

    Circle c3;
    c3.setCenter(50,50);
    c3.opEsc(y,y);
    c3.draw();

    Circle c4;
    c4.setRadio(15);
    c4.setCenter(10,200);
    c4.opTras(x,100);
    c4.draw();

    Circle c5;
    c5.setRadio(15);
    c5.setCenter(10,200);
    c5.opTras(a,100);
    c5.draw();

    Circle c6;
    c6.setRadio(50);
    c6.setCenter(10,0);
    c6.opTras(100,b);
    c6.draw();
    Circle c7;
    c7.setRadio(100);
    c7.setCenter(10,0);
    c7.opTras(120,b);
    c7.draw();
    Circle c8;
    c8.setRadio(150);
    c8.setCenter(10,0);
    c8.opTras(130,b);
    c8.draw();
}
void dibujaCuadrado(){
    Square s1;
    s1.opTras(0,20);
    s1.opTras(x,0);
    s1.draw();
    Square s2;
    s2.opTras(0,20);
    s2.opTras(a,0);
    s2.draw();
    Square s3;
    s3.opTras(50,125);
    s3.opRot(-d ,0 ,0 );
    s3.draw();
    Square s4;
    s4.opTras(200,125);
    s4.opRot(d ,0 ,0 );
    s4.draw();
    Square s5;
    s5.setVertex(0,0,100,0,100,100,0,100);
    s5.opTras(0,20);
    s5.opTras(x,130);
    s5.draw();
    Square s6;
    s6.opTras(0,20);
    s6.opTras(a,130);
    s6.draw();
    //Escala
    Square s7;
    s7.setVertex(0,0,5,0,5,5,0,5);
    s7.opEsc(e,e);
    s7.draw();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    dibujaTriangulo();
    dibujaCirculo();
    dibujaCuadrado();
    glutSwapBuffers();

    x++;
    if( x > 200){
        x = 0;
    }
    y++;
    if( y > 200){
        y = 0;
    }
    d+=10;
    if( d == 360){
        d = 0;
    }
    a--;
    if( a == 0){
        a = 250;
    }
    b--;
    if( b == 0){
        b = 250;
    }
    e = e + 0.05;
    if( e == 200){
        b = 0;
    }
    //t.opEsc(2,2);
    //t.opRot(90,0,0);


    //Circle c;
    //c.draw();
    //c.setVertex(0,0,10,17.3205,20,0);
    //c.setRadio(54);
    //c.draw();
    //c.opTras(25,0);
    //c.draw();
    //c.opEsc(5,5);
    //c.draw();
    //c.opRot(45,0,0);
    //c.draw();

    glFlush();
    Sleep(50);
 }
void init()
{
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.5);
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 499, 0, 499);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) //Se repite una vez y se queda en un loop  *FLUSH libera a la pantalla
{

    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500); /* ventana 500x500 pixeles */
    glutInitWindowPosition(50,50); /* coloca la ventana de despliegue en esq. sup. izq */
    glutCreateWindow("Parcial 1"); /* título de la ventana*/
    init(); /* fija o establece los atributos */
    glutDisplayFunc(display); /*llama a la funcion display cuando se abre la ventana */
    //While infinitp
    glutIdleFunc(display);//Mientras el usuario no haga nada va seguir dibujando una pantalla 24 veces x seg
    glutMainLoop(); /* entra a un ciclo de evento */
}


