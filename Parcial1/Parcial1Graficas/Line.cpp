#include "Line.h"
#include <GL/glut.h>
#include <stdlib.h>

Line::Line(){
}

Line::~Line(){
    p1.setValues(0,0);
    p2.setValues(0,0);
}

void Line::setValues(Point pA, Point pB){
    int x = pA.getX();
    int y = pA.getY();
	p1.setValues(x,y);
	x = pB.getX();
	y = pB.getY();
	p2.setValues(x,y);
}

void Line::draw(){
    int x1 = p1.getX();
    int y1 = p1.getY();
    int x2 = p2.getX();
    int y2 = p2.getY();

    int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		p1.setValues(x, y);
		p1.draw();
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			p1.setValues(x, y);
            p1.draw();
		}

	} else {
		p1.setValues(x, y);
		p1.draw();
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			p1.setValues(x, y);
            p1.draw();
		}
	}
}
int Line::getValueX(){
    return p1.getX();
}
int Line::getValueY(){
    return p1.getY();
}


