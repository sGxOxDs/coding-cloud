// Function prototype.

#ifndef MATRIX_H
#define MATRIX_H
struct Matrix
{
    int **mat;
    int *temp;
    int col=0;
    int row=0;
    int createMatrixFromArray();
    int deletemat();
};
void loadmatrix(Matrix &x,char path[]);
Matrix multiplicationmatrix(Matrix x,Matrix y);
void printmatrix(Matrix x);
#endif /* AVERAGE_H */
