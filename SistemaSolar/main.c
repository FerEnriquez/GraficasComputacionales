#include <GL/glut.h>
#include <stdlib.h>
//GLfloat anguloSolX = 0.0f;
GLfloat anguloSol = 0.0f;
GLfloat anguloLuna = 0.0f;

GLfloat anguloMercurio = 0.0f;
GLfloat anguloVenus = 0.0f;
GLfloat anguloTierra = 0.0f;
GLfloat anguloMarte = 0.0f;
GLfloat anguloJupiter = 0.0f;


GLint ancho, alto;
int hazPerspectiva = 1;

//Variables para definir la posicion del observador
//gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z)
float EYE_X=0.0;
float EYE_Y=0.0;
float EYE_Z=5.0;
float CENTER_X=0;
float CENTER_Y=0;
float CENTER_Z=0;
float UP_X=0;
float UP_Y=1;
float UP_Z=0;

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(hazPerspectiva)
      gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 1.0f, 80.0f);
    else
      glOrtho(-6, 6, -6, 6, 1, 20);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
    ancho = width;
    alto = height;
}

void Sol(){
     glPushMatrix();
     glRotatef(90, 1.0f, 0.0f, 0.0f);
     glRotatef(anguloSol, 0.0f, 0.0f, 1.0f);
     glColor3f(1.0,1.0,0.0);
     glutWireSphere(1.0f,20,20);
     glPopMatrix();
 }

void Luna(float x, float y, float z, float a, float b, float c){
     glPushMatrix();
     glRotatef(anguloLuna,x,y,z);
     glTranslatef(a,b,c);
     glColor3f(1.0,1.0,1.0);
     glutWireSphere(0.05f,10,10);
     glPopMatrix();
}

void Mercurio(){
     glPushMatrix();
     glRotatef(anguloMercurio,0,1,0);
     glTranslatef(2.5,0.0,0.0);
     glColor3f(1.0,0.0,1.0);
     glutWireSphere(0.3f,10,10);
     Luna(1.0,0.0,0.0,0.0,0.5,0.0);
     glPopMatrix();
}

void Venus(){
     glPushMatrix();
     glRotatef(anguloVenus,0,0,1);
     glTranslatef(2.5,0.0,0.0);
     glColor3f(0.0,1.0,0.0);
     glutWireSphere(0.3f,10,10);
     Luna(1.0,0.0,0.0,0.0,0.5,0.0);
     Luna(0.0,1.0,0.0,0.5,0.0,0.0);
     glPopMatrix();
}

void Tierra(){
     glPushMatrix();
     glRotatef(anguloTierra,0,0,1);
     glTranslatef(0.0,2.0,0.0);
     glColor3f(0.0,0.0,1.0);
     glutWireSphere(0.3f,10,10);
     Luna(1.0,0.0,0.0,0.0,0.5,0.0);
     glPopMatrix();
}
void Marte(){
     glPushMatrix();
     glRotatef(anguloMarte,0,1,0);
     glTranslatef(2.5,0.0,0.0);
     glColor3f(1.0,0.0,0.0);
     glutWireSphere(0.3f,10,10);
     Luna(1.0,0.0,0.0,0.0,0.5,0.0);
     Luna(0.0,1.0,0.0,0.5,0.0,0.0);
     glPopMatrix();
}
void Jupiter(){
     glPushMatrix();
     glRotatef(anguloJupiter,0,0,1);
     glTranslatef(2.5,0.0,0.0);
     glColor3f(1.0,0.5,0.0);
     glutWireSphere(0.5f,10,10);
     Luna(1.0,0.0,0.0,0.0,0.5,0.0);
     Luna(0.0,1.0,0.0,0.5,0.0,0.0);
     Luna(0.0,0.0,1.0,0.0,0.5,0.0);
     glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);

    Sol();
    Mercurio();
    Venus();
    Tierra();
    Marte();
    Jupiter();
    glutSwapBuffers();

    anguloSol+=0.1f;
    anguloLuna+=0.6f;

    anguloMercurio+=0.5f;
    anguloVenus+=0.1f;
    anguloTierra+=0.2f;
    anguloMarte+=0.1f;
    anguloJupiter+=0.02f;

}

void init()
{
   glClearColor(0,0,0,0);
   glEnable(GL_DEPTH_TEST);
   ancho = 400;
   alto = 400;
}

void idle()
{
     display();
 }

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'p':
    case 'P':
      hazPerspectiva=1;
      reshape(ancho,alto);
      break;

    case 'o':
    case 'O':
      hazPerspectiva=0;
      reshape(ancho,alto);
      break;

    case 27:   // escape
      exit(0);
      break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Sol Tierra Luna");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
