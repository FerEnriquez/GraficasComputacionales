#include <GL/glut.h>
#include <stdio.h>
#include "Star.h"

Star::Star(){
    p1.Move(0.0,1.0,0.0);

    p2.RotateAxis(0.0,0.0,90.0);

    p3.RotateAxis(0.0,0.0,270);
    p3.Move(0.0,1.0,0.0);
    p3.Move(1.0,0.0,0.0);

    p4.RotateAxis(180,0.0,0.0);
    p4.Move(0.0,0.0,1.0);
}
Star::~Star(){
}
void Star::draw(){
    c.draw(1.0f,1.0f,0.0f);
    p1.draw(1.0f,1.0f,0.0);  //Arriba
    p2.draw(1.0f,1.0f,0.0);  //Izquierda
    p3.draw(1.0f,1.0f,0.0);  //Abajo
    p4.draw(1.0f,1.0f,0.0);    //Derecha
}
void Star::save(){
    c.save();
    p1.save();
    p2.save();
    p3.save();
    p4.save();
}
void Star::undo(){
    c.undo();
    p1.undo();
    p2.undo();
    p3.undo();
    p4.undo();
}
void Star::Move(float x, float y, float z){
    c.Move(x,y,z);
    p1.Move(x,y,z);
    p2.Move(x,y,z);
    p3.Move(x,y,z);
    p4.Move(x,y,z);
}
void Star::Scale(float x, float y, float z){
    c.Scale(x,y,z);
    p1.Scale(x,y,z);
    p2.Scale(x,y,z);
    p3.Scale(x,y,z);
    p4.Scale(x,y,z);

}
void Star::RotateAxis(float x, float y, float z){
    c.RotateAxis(x,y,z);
    p1.RotateAxis(x,y,z);
    p2.RotateAxis(x,y,z);
    p3.RotateAxis(x,y,z);
    p4.RotateAxis(x,y,z);
}
void Star::RotateFree(float d){
    c.RotateFree(d);
    p1.RotateFree(d);
    p2.RotateFree(d);
    p3.RotateFree(d);
    p4.RotateFree(d);
}
void Star::setAxis(float x1, float y1, float z1, float x2, float y2, float z2){
    c.setPoints( x1,  y1,  z1,  x2,  y2,  z2);
    p1.setPoints( x1,  y1,  z1,  x2,  y2,  z2);
    p2.setPoints( x1,  y1,  z1,  x2,  y2,  z2);
    p3.setPoints( x1,  y1,  z1,  x2,  y2,  z2);
    p4.setPoints( x1,  y1,  z1,  x2,  y2,  z2);
}


