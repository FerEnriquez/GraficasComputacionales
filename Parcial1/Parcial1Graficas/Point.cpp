#include "Point.h"
Point::Point(){
	coord[0] = 0;
	coord[1] = 0;
}
Point::~Point(){

}
void Point::setValues(int x1, int y1){
    coord[0] = x1;
    coord[1] = y1;
}
int Point::getX(){
	return coord[0];
}
int Point::getY(){
	return coord[1];
}
int* Point::getValues(){
    return coord;
}
void Point::draw(){
    glBegin(GL_POINTS);
        glVertex2iv(coord);
    glEnd();
}
