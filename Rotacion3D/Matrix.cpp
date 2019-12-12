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
void Matrix:: setPoint(float a, float b, float c){
    point[0] = a;
    point[1] = b;
    point[2] = c;
    point[3] = 1;
}
void Matrix::Multiply(){
    int j,k;
    float x[3];
    float sum = 0;
    float mult = 0;
    for(j = 0; j < 4; j++){
        for(k = 0; k < 4; k++){
            mult = mat[j][k] * point[k];
            //printf("mult -> %f ", sum);
            sum = sum + mult;
        }
        x[j] = sum;
        //printf(" sum -> %f ", sum);
        //printf("\n");
        sum = 0;
    }
    mat[0][0] = x[0];
    mat[1][0] = x[1];
    mat[2][0] = x[2];
//    printf(" X | %f |", x[0]);
//    printf(" Y | %f |", x[1]);
//    printf(" Z | %f |", x[2]);
//     printf("\n");
}

void Matrix::RotateX(float d){
    float val = PI / 180.0;
    mat[1][1] = cos(d*val);
    mat[1][2] = -sin(d*val);
    mat[2][1] = sin(d*val);
    mat[2][2] = cos(d*val);
//    printf("AGGUUULOOOTEEEES\n");
//    printf(" | %f |",  mat[1][1]);
//    printf(" | %f |",  mat[1][2]);
//    printf(" | %f |",  mat[2][1]);
//    printf(" | %f |",  mat[2][2]);
//     printf("\n");

    Multiply();
}
void Matrix::RotateY(float d){
    float val = PI / 180.0;
    mat[0][0] = cos(d*val);
    mat[2][0] = -sin(d*val);
    mat[0][2] = sin(d*val);
    mat[2][2] = cos(d*val);

    Multiply();
}
void Matrix::RotateZ(float d){
    float val = PI / 180.0;
    mat[0][0] = cos(d*val);
    mat[0][1] = -sin(d*val);
    mat[1][0] = sin(d*val);
    mat[1][1] = cos(d*val);

   // printMat();
    Multiply();
}
float Matrix::newPointX(){
    return mat[0][0];
}
float Matrix::newPointY(){
    return mat[1][0];
}
float Matrix::newPointZ(){
    return mat[2][0];
}
