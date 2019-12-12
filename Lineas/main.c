#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#define PI 3.1416f
#include <math.h>



GLfloat sizep;
GLfloat white[3] = {1.0, 0.0, 0.0};
int npoints = 10;
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10); //Plantear tu propio cartesiano, por ejemplo -10 en x y y
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLfloat angulo, delta;
    GLfloat x, y;
    float r;

    float b = sqrt((float)360);
    float a = sqrt((float)npoints);
    delta = b/a;
    angulo = 0;
    glColor3fv(white);
    glPointSize(2.0);

    glLineWidth(1.0);
    glColor3f(1.0,0.0,0.0);
    a = 0;
    b = 0;
    for (int i=0; i < npoints; i++) {
        r = -3 + 4 * cos(angulo);
        x = r*sin(angulo);
        y = r*cos(angulo);
        glBegin(GL_POINTS);
            glVertex2f(x,y);
        //if ( i != 0){
            glBegin(GL_LINES);
                glVertex3f(a, b, 0.0);
                glVertex3f(x, y, 0);
        //}
        a = x;
        b = y;
        glEnd();
        angulo += delta;
        }
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(40,40);
    glutInitWindowSize(600,600);
    glutCreateWindow("Círculo de líneas");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

