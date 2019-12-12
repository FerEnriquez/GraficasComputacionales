#include <GL/glut.h>
#include <stdio.h>
#include "Ship.h"

Ship::Ship(){
    c.Scale(2.0,0.0,0.0);
    py.RotateAxis(0.0,0.0,90.0);
    p1.RotateAxis(0.0,0.0,90.0);
    p1.Move(2.0,0.0,0.0);
    p1.Move(0.0,0.0,0.5);
    p2.RotateAxis(0.0,0.0,90.0);
    p2.Move(2.0,0.0,0.0);
    p2.Move(0.0,0.0,-0.5);

}
Ship::~Ship(){
}
void Ship::draw(){
    c.draw(0.0f,1.0f,1.0f);
    py.draw(0.0f,1.0f,1.0f);
    p1.draw(0.0f,1.0f,1.0f);
    p2.draw(0.0f,1.0f,1.0f);
}
void Ship::save(){
    c.save();
    py.save();
    p1.save();
    p2.save();
}
void Ship::undo(){
    c.undo();
    py.undo();
    p1.undo();
    p2.undo();
}
void Ship::Move(float x, float y, float z){
    c.Move(x,y,z);
    py.Move(x,y,z);
    p1.Move(x,y,z);
    p2.Move(x,y,z);
}
void Ship::Scale(float x, float y, float z){
    c.Scale(x,y,z);
    py.Scale(x,y,z);
    p1.Scale(x,y,z);
    p2.Scale(x,y,z);
}
void Ship::RotateAxis(float x, float y, float z){
    c.RotateAxis(x,y,z);
    py.RotateAxis(x,y,z);
    p1.RotateAxis(x,y,z);
    p2.RotateAxis(x,y,z);
}
void Ship::RotateFree(float d){
    c.RotateFree(d);
    py.RotateFree(d);
    p1.RotateFree(d);
    p2.RotateFree(d);
}
void Ship::setAxis(float x1, float y1, float z1, float x2, float y2, float z2){
    c.setPoints( x1,  y1,  z1,  x2,  y2,  z2);
    py.setPoints( x1,  y1,  z1,  x2,  y2,  z2);
    p1.setPoints( x1,  y1,  z1,  x2,  y2,  z2);
    p2.setPoints( x1,  y1,  z1,  x2,  y2,  z2);
}
