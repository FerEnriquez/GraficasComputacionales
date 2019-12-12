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
            else
                mat[i][j] = 0.0;
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
void Matrix::Multiply(float mt[4][4]){
    int i, j, k;
    float sum = 0;
    float mult = 0;
    float x[4][4];
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            for(k = 0; k < 4; k++){
                mult = mat[i][k] * mt[k][j];
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
void Matrix::t(float a, float b, float c){
    float met[4][4];
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(i == j){
                met[i][j] = 1.0;
            }
            else
                met[i][j] = 0.0;
        }
    }
    met[0][3] = a;
    met[1][3] = b;
    met[2][3] = c;
    Multiply(met);
}
void Matrix::invT(float a, float b, float c){
    float met[4][4];
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(i == j){
                met[i][j] = 1.0;
            }
            else
                met[i][j] = 0.0;
        }
    }
    met[0][3] = -a;
    met[1][3] = -b;
    met[2][3] = -c;
    Multiply(met);
}
void Matrix::RX(float b, float c, float d){
    float met[4][4];
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(i == j){
                met[i][j] = 1.0;
            }
            else
                met[i][j] = 0.0;
        }
    }
    met[1][1] = c/d;
    met[1][2] = b/d;
    met[2][1] = -b/d;
    met[2][2] = c/d;
    Multiply(met);
}

void Matrix::InvRX(float b, float c, float d){
    float met[4][4];
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(i == j){
                met[i][j] = 1.0;
            }
            else
                met[i][j] = 0.0;
        }
    }
    met[1][1] = -c/d;
    met[1][2] = -b/d;
    met[2][1] = b/d;
    met[2][2] = -c/d;
    Multiply(met);
}

void Matrix::RY(float a, float d){
    float met[4][4];
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(i == j){
                met[i][j] = 1.0;
            }
            else
                met[i][j] = 0.0;
        }
    }
    met[0][0] = d;
    met[0][2] = a;
    met[2][0] = -a;
    met[2][2] = d;
    Multiply(met);
}
void Matrix::InvRY(float a, float d){
    float met[4][4];
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(i == j){
                met[i][j] = 1.0;
            }
            else
                met[i][j] = 0.0;
        }
    }
    met[0][0] = d;
    met[0][2] = -a;
    met[2][0] = a;
    met[2][2] = d;
    Multiply(met);
}
void Matrix::RZ(float d){
    float met[4][4];
    int i,j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(i == j){
                met[i][j] = 1.0;
            }
            else
                met[i][j] = 0.0;
        }
    }
    float val = PI / 180.0;
    mat[0][0] = cos(d*val);
    mat[0][1] = -sin(d*val);
    mat[1][0] = sin(d*val);
    mat[1][1] = cos(d*val);
    Multiply(met);
}
void Matrix::getPoints(float a, float b, float c){
    float mPoints[4];
    mPoints[0] = a;
    mPoints[1] = b;
    mPoints[2] = c;
    mPoints[3] = 1.0;
    int j, k;
    float x[4];
    float sum = 0;
    float mult = 0;
    for(j = 0; j < 4; j++){
        for(k = 0; k < 4; k++){
            mult = mat[j][k] * mPoints[k];
            //printf("mat : %f / mPoint : %f \n", mat[j][k], mPoints[k]);
            sum = sum + mult;
        }
        x[j] = sum;
      //  printf("sum : %f \n", sum);
        sum = 0;
    }
    mat[0][0] = x[0];
    mat[1][0] = x[1];
    mat[2][0] = x[2];
}

float Matrix:: newX(){
    return mat[0][0];
}
float Matrix:: newY(){
    return mat[1][0];
}
float Matrix:: newZ(){
    return mat[2][0];
}
