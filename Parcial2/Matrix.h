#include <GL/glut.h>
#include <stdlib.h>

#ifndef MATRIX_H
#define MATRIX_H

class Matrix;

class Stack {
  private:
    Matrix* stack[1000];
    int top = -1;

  public:
    void push(Matrix* mat) {
        stack[++top] = mat;
    };
    Matrix* pop() {
        return stack[top--];
    };
};

class Matrix{
    private :
        float mat[4][4];
        Stack mystack;
    public:
        Matrix();
        ~Matrix();
        void clean();
        void printMat();

        float getValue(int i,int j);
        void setValue(int i,int j, float x);

        void pop();
        void push();

        void MultiplyA(Matrix aux);
        void MultiplyB(float point[4]);

        void movX(float p);
        void movY(float p);
        void movZ(float p);

        void scaleX(float s);
        void scaleY(float s);
        void scaleZ(float s);

        void rotX(float d);
        void rotY(float d);
        void rotZ(float d);
        //Free rotation
        void T(float a, float b, float c);
        void invT(float a, float b, float c);
        void RX(float b, float c, float d);
        void invRX(float b, float c, float d);
        void RY(float a, float d);
        void invRY(float a, float d);
        void RZ(float d);
        float getX();
        float getY();
        float getZ();
};
#endif
