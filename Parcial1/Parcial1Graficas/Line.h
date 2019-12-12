#include <GL/glut.h>
#include <stdlib.h>
#include "Point.h"
#ifndef LINE_H
#define LINE_H
class Line{
	private:
		Point p1;
		Point p2;
	public:
		Line();
		~Line();
		void setValues(Point pA, Point pB);
		int getValueX();
		int getValueY();
        void draw();
};
#endif
