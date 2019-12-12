
#include <GL/glut.h>
#include <GL/glext.h>
#include <stdlib.h>

#include "FreeImage.h"

//se define la cantidad de texturas que se manejaran
#define NTextures 1
GLuint	texture[NTextures];
//variables para manejo de texturas
char *texturefiles[] = {
	"imagen1.bmp",
};

bool readImage()
{
  	//image format
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	//pointer to the image, once loaded
	FIBITMAP *dib(0), *dib_copy(0);
	//pointer to the image data
	BYTE* bits(0);
	//image width and height
	unsigned int width(0), height(0);
	//check the file signature and deduce its format
	fif = FreeImage_GetFileType(texturefiles[0], 0);
	//if still unknown, try to guess the file format from the file extension
	if(fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(texturefiles[0]);
	//if still unkown, return failure
	if(fif == FIF_UNKNOWN)
		return false;

	//check that the plugin has reading capabilities and load the file
	if(FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, texturefiles[0], BMP_DEFAULT);
	//if the image failed to load, return failure
	if(!dib)
		return false;
	//conversion to 24 bit deep color
	dib_copy = FreeImage_ConvertTo32Bits(dib);
	FreeImage_Unload(dib);
	dib = dib_copy;

	//TEXTURE GENERATION

	//retrieve the image data
	bits = FreeImage_GetBits(dib);
	//get the image width and height
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);
	//if this somehow one of these failed (they shouldn't), return failure
	if((bits == 0) || (width == 0) || (height == 0))
		return false;

	//generate an OpenGL texture ID for this texture
	glGenTextures(1, &texture[0]);
	//bind to the new texture ID
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	//store the texture data for OpenGL use
	// ** AGREGADO ** (filtros para la textura y condicional de mipmap) //
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0,
                 GL_BGRA, GL_UNSIGNED_BYTE, bits);

	//Free FreeImage's copy of the data
	FreeImage_Unload(dib);


	//return success
	return true;

}

void display()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    //activa la textura
    glColor3f(1.0,1.0,1.0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_TRIANGLES);
        //glColor3f(0.0f,1.0f,0.0f);
        glTexCoord2f(0.5f,0.0f);
		glVertex2f(0.0f, 1.0f);

		//glColor3f(0.0f,1.0f,0.0f);
        glTexCoord2f(0.0f,1.0f);
		glVertex2f(-1.0f,-1.0f);

		//glColor3f(0.0f,1.0f,0.0f);
        glTexCoord2f(1.0f,1.0f);
		glVertex2f( 1.0f,-1.0f);
	glEnd();

    glFlush();
}

void init()
{ int r;
     //Establece el color de la ventana de visualizacion
     //Los tres primeros parametros corresponden al RGB
     //El cuarto parametro corresponde al valor alfa, que permite el efecto de transparencias
     //0: objeto totalmente transparente; 1: objeto totalmente opaco
     glClearColor(1.0, 1.0, 1.0, 1.0);
     //establece los parametros de proyeccion ortogonal
     //Se visualizara una proyeccion bidimensional de dimensiones 200 x 150
     //(0,0): esquina inferior izquierda: punto de referencia de esta ventana
     glMatrixMode(GL_PROJECTION);
     gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
     readImage();
     //std::cout <<
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Triangulo a color");
    //if(!LoadTextures()) return 0;
    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
