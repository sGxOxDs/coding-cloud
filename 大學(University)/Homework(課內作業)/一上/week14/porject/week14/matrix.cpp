// Compute average in vector.
// Standard includes
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
// Private header file with prototype for average.
#include "matrix.h"

void loadmatrix(Matrix &x,char path[])
{
    fstream file(path,ios::in);
    if(!file)
    {
        cout<<"can't open"<<endl;
        return;
    }
    stringstream ss,sn;
    string value,temp;
    ss.str("");
    ss.clear();
    int l=0;
    for(int i=0 ;getline(file,temp);i++ )
    {
        ss.str(temp);
        for(int j=0 ;getline(ss,value,',');j++ )
        {
            if(i==0&&j==0)
            {
                sn.str("");
                sn.clear();
                sn<<value;
                sn>>x.col;
            }
            else if(i==0&&j==1)
            {
                sn.str("");
                sn.clear();
                sn<<value;
                sn>>x.row;
            }
            else if(i>0)
            {
                int tmp;
                sn.str("");
                sn.clear();
                sn<<value;
                sn>>x.temp[l++];
            }
        }
        if(i==0)
            x.temp=new int [x.col*x.row]();
        ss.clear();
    }
    x.createMatrixFromArray();
}

Matrix multiplicationmatrix(Matrix x,Matrix y)
{
    Matrix Ans;
    Matrix X;
    Matrix Y;

    if(x.row==y.col)
    {
        X=x;
        Y=y;
    }
    else if(x.col==y.row)
    {
        X=y;
        Y=x;
    }
    else
        return Ans;

    Ans.row=Y.row;
    Ans.col=X.col;

    Ans.mat=new int* [Ans.col]();
    for(int i=0;i<Ans.col;i++)
        Ans.mat[i]=new int [Ans.row]();

    for(int x=0;x<Ans.row;x++)
        for(int y=0;y<Ans.col;y++)
            for(int z=0;z<X.row;z++)
                Ans.mat[y][x]+=X.mat[y][z]*Y.mat[z][x];
    return Ans;
}

void printmatrix(Matrix x)
{
    for(int i=0;i<x.col;i++)
    {
        for(int j=0;j<x.row;j++)
            cout<<x.mat[i][j]<<" ";
        cout<<endl;
    }
}

int Matrix::createMatrixFromArray()
{
        mat=new int* [col]();

        int l=0;
        for(int i=0;i<col;i++)
        {
            mat[i]=new int [row]();
            for(int j=0;j<row;j++)
                mat[i][j]=temp[l++];
        }
        return 1;
}
int Matrix::deletemat()
{
        for(int i=0;i<col;i++)
        {
            delete[] mat[i];
            mat[i] = NULL;
        }
        delete[] mat;
        mat = NULL;
        return 1;
}
