#include <iostream>
//指標的ArraySize階方陣的乘法運算

using namespace std;

int createMatrixFromArray(int** &, int*);
int** multiplicateMatrix(int**, int**);
int destroyMatrix(int**);
int printMatrix(int**);

int ArraySize = 3;

int main()
{
    int **mat1;
    int **mat2;
    int **mat3;

    int *temp1=new int [ArraySize*ArraySize]();
    int *temp2=new int [ArraySize*ArraySize]();

    for(int i=0;i<ArraySize*ArraySize;i++)
        cin >> temp1[i];
    cout<<"====="<<endl;
    for(int i=0;i<ArraySize*ArraySize;i++)
        cin >> temp2[i];

    createMatrixFromArray(mat1, temp1);
    createMatrixFromArray(mat2, temp2);

    mat3=multiplicateMatrix(mat1, mat2);

    printMatrix(mat1);
    printMatrix(mat2);
    printMatrix(mat3);

    destroyMatrix(mat1);
    destroyMatrix(mat2);
    destroyMatrix(mat3);
}
int createMatrixFromArray(int **&mat, int *temp)
{
    mat=new int* [ArraySize]();

    int l=0;
    for(int i=0;i<ArraySize;i++)
    {
        mat[i]=new int [ArraySize]();
        for(int j=0;j<ArraySize;j++)
            mat[i][j]=temp[l++];
    }
    return 1;
}
int** multiplicateMatrix(int**mat1, int**mat2)
{
    int **mat3=new int* [ArraySize]();
    for(int i=0;i<ArraySize;i++)
        mat3[i]=new int [ArraySize]();

    for(int x=0;x<ArraySize;x++)
        for(int y=0;y<ArraySize;y++)
            for(int z=0;z<ArraySize;z++)
                mat3[x][y]+=mat1[x][z]*mat2[z][y];

    return mat3;
}
int destroyMatrix(int **mat)
{
    for(int i=0;i<ArraySize;i++)
    {
        delete[] mat[i];
        mat[i] = NULL;
    }
    delete[] mat;
    mat = NULL;
    return 1;
}
int printMatrix(int **mat)
{
    cout<<"---"<<endl;
    for(int i=0;i<ArraySize;i++)
    {
        for(int j=0;j<ArraySize;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    return 1;
}

