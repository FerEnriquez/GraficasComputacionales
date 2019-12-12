#include <GL/glut.h>
#include <stdlib.h>
#ifndef MATRIX_H
#define MATRIX_H
class Matrix{
    private :
        float mat[3][3];

    public:
        Matrix();
        ~Matrix();
        void clean();
        void printMat();
        void Multiply(float mt[3][3]);
        void Rotate(float D);
        void Scale(float x, float y);
        void Move(float x, float y);
        //Mando puntos pivote
        void Pivote(float x, float y);
        //Regreso posición original
        void BackPivote(float x, float y);
        //Punto a mover, obtener resultaoo
        float newPointX(float a, float b);
        float newPointY();

};
#endif
