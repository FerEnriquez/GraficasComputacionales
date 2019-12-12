#include <GL/glut.h>
#include <stdlib.h>
#ifndef POINT_H
#define POINT_H
class Point{
	private:
		int coord[2];
	public:
		Point();
		~Point(); //Destructor
		void setValues(int,int);
		int getX();
		int getY();
		int* getValues(); //La dirección de memoria
		void draw();
};
#endif
