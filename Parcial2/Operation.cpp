#include "Operation.h"
#include <stdio.h>
#include <stack>
#include <math.h>
using namespace std;
#define PI 3.14159265
Operation::Operation(){
    mat.push();
}
Operation::~Operation(){
}
void Operation:: undo(){
    mat.pop();
}
void Operation:: save(){
    mat.push();
}
void Operation:: setPoint(float a, float b, float c){
    point[0] = a;
    point[1] = b;
    point[2] = c;
    point[3] = 1;
}
void Operation::Move(float x, float y, float z){
    mat.clean();
    if(x != 0.0){
        mat.movX(x);
        //mat.push();
    } // Y
    else if(y != 0.0){
        mat.movY(y);
        //mat.push();
    } // Z
    else if(z != 0.0){
        mat.movZ(z);
        //mat.push();
    }
    mat.MultiplyB(point);
    //mat.push();
}
void Operation::Scale(float x, float y, float z){
    mat.clean();
    //All options
    if(x != 0 && y != 0 && z !=0 ){
        mat.scaleX(x);
        mat.scaleY(y);
        mat.scaleZ(z);
        mat.MultiplyB(point);
    } // X
    else if(x != 0){
        mat.scaleX(x);
        mat.MultiplyB(point);
    } // Y
    else if(y != 0){
        mat.scaleY(y);
        mat.MultiplyB(point);
    } // Z
    else if(z != 0){
        mat.scaleZ(z);
        mat.MultiplyB(point);
    }

}
void Operation::RotateAxis(float x, float y, float z){
    mat.clean();
    if(x != 0){
        mat.rotX(x);
        mat.MultiplyB(point);
    } // Y
    if(y != 0){
        mat.rotY(y);
        mat.MultiplyB(point);
    } // Z
    if(z != 0){
        mat.rotZ(z);
        mat.MultiplyB(point);
    }
}
void Operation::setPoints(float x1, float y1, float z1, float x2, float y2, float z2){
    axis[0] = x1;
    axis[1] = y1;
    axis[2] = z1;
    axis[3] = x2;
    axis[4] = y2;
    axis[5] = z2;
}
void Operation::RotateFree(float dg){
    //Set axis
    float a1 = axis[3] - axis[0];
    float b1 = axis[4] - axis[1];
    float c1 = axis[5] - axis[2];
    a1 = a1*a1;
    b1 = b1*b1;
    c1 = c1*c1;
    float v = a1 + b1 + c1;
    v = sqrt(v);
    float a = (axis[3] - axis[0]) / v;
    float b = (axis[4] - axis[1]) / v;
    float c = (axis[5] - axis[2]) / v;
    float d = (b*b) + (c*c);
    d = sqrt(d);

    mat.clean();
    aux.clean();
    mat.T(axis[0], axis[1], axis[2]);
    aux.RX(a,c,d);
    mat.MultiplyA(aux);

    mat.clean();
    aux.clean();
    aux.RY(a,d);
    mat.MultiplyA(aux);

    aux.clean();
    aux.RZ(dg);
    mat.MultiplyA(aux);

    aux.clean();
    aux.invRY(a,d);
    mat.MultiplyA(aux);

    aux.clean();
    aux.invRX(b,c,d);
    mat.MultiplyA(aux);

    aux.clean();
    aux.invT(axis[0], axis[1], axis[2]);

    mat.MultiplyB(point);
}
float Operation::newPointX(){
    return mat.getX();
}
float Operation::newPointY(){
    return mat.getY();
}
float Operation::newPointZ(){
    return mat.getZ();
}

