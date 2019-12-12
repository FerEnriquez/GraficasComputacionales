#include "Matrix.h"
#include <stdio.h>
#include <math.h>
#define PI 3.14159265

Matrix::Matrix(){
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4  ; j++){
            if(i == j){
                mat[i][j] = 1.0;
            }
            else
                mat[i][j] = 0.0;
        }
    }

}
Matrix::~Matrix(){

}
void Matrix::clean(){
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(i == j){
                mat[i][j] = 1.0;
            }
            else{
                mat[i][j] = 0.0;
            }
        }
    }
}
void Matrix::printMat(){
    int i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("| %f |", mat[i][j]);
        }
        printf("\n");
    }
    printf("__________________________________\n");
}
void Matrix:: push(){
    Matrix *tmp;
    tmp = new Matrix();
    for(int i; i < 4; i++){
        for(int j; j < 4; j++){
            tmp->mat[i][j];
        }
    }
    mystack.push(tmp);
}
void Matrix:: pop(){
    mystack.pop();
}
float Matrix::getValue(int i, int j){
    return mat[i][j];
}
void Matrix::setValue(int i, int j, float x){
    mat[i][j] = x;
}
void Matrix::MultiplyA(Matrix met){
    int i, j, k;
    float sum = 0;
    float mult = 0;
    float x[4][4];
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            for(k = 0; k < 4; k++){
                mult = mat[i][k] * met.getValue(k,j);
                sum = sum + mult;
            }
        x[i][j] = sum;
        sum = 0;
        }
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
           mat[i][j] = x[i][j];
        }
    }

}
void Matrix::MultiplyB(float point[4]){
    int j,k;
    float x[3];
    float sum = 0;
    float mult = 0;
    for(j = 0; j < 4; j++){
        for(k = 0; k < 4; k++){
            mult = mat[j][k] * point[k];
            sum = sum + mult;
        }
        x[j] = sum;
        sum = 0;
    }
    mat[0][0] = x[0];
    mat[1][0] = x[1];
    mat[2][0] = x[2];
}
void Matrix::movX(float p){
    mat[0][3] = p;
}
void Matrix::movY(float p){
    mat[1][3] = p;
}
void Matrix::movZ(float p){
    mat[2][3] = p;
}
void Matrix::scaleX(float s){
    mat [0][0] = s;
}
void Matrix::scaleY(float s){
    mat [1][1] = s;
}
void Matrix::scaleZ(float s){
    mat [2][2] = s;
}
void Matrix::rotX(float d){
    float val = PI / 180.0;
    mat[1][1] = cos(d*val);
    mat[1][2] = -sin(d*val);
    mat[2][1] = sin(d*val);
    mat[2][2] = cos(d*val);
}
void Matrix::rotY(float d){
    float val = PI / 180.0;
    mat[0][0] = cos(d*val);
    mat[2][0] = -sin(d*val);
    mat[0][2] = sin(d*val);
    mat[2][2] = cos(d*val);

}
void Matrix::rotZ(float d){
    float val = PI / 180.0;
    mat[0][0] = cos(d*val);
    mat[0][1] = -sin(d*val);
    mat[1][0] = sin(d*val);
    mat[1][1] = cos(d*val);
}
void Matrix::T(float a, float b, float c){
    mat[0][3] = a;
    mat[1][3] = b;
    mat[2][3] = c;
}
void Matrix::invT(float a, float b, float c){
    mat[0][3] = -a;
    mat[1][3] = -b;
    mat[2][3] = -c;
}
void Matrix::RX(float b, float c, float d){
    mat[1][1] = c/d;
    mat[1][2] = b/d;
    mat[2][1] = -b/d;
    mat[2][2] = c/d;
}
void Matrix::invRX(float b, float c, float d){
    mat[1][1] = -c/d;
    mat[1][2] = -b/d;
    mat[2][1] = b/d;
    mat[2][2] = -c/d;
}
void Matrix::RY(float a, float d){
    mat[0][0] = d;
    mat[0][2] = a;
    mat[2][0] = -a;
    mat[2][2] = d;
}
void Matrix::invRY(float a, float d){
    mat[0][0] = d;
    mat[0][2] = -a;
    mat[2][0] = a;
    mat[2][2] = d;
}
void Matrix::RZ(float d){
    float val = PI / 180.0;
    mat[0][0] = cos(d*val);
    mat[0][1] = -sin(d*val);
    mat[1][0] = sin(d*val);
    mat[1][1] = cos(d*val);
}
float Matrix::getX(){
    return mat[0][0];
}
float Matrix::getY(){
    return mat[1][0];
}
float Matrix::getZ(){
    return mat[2][0];
}



