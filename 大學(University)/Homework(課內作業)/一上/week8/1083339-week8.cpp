#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
//成績排序程式

using namespace std;

float findMedianScore(int *ptrScore, int amounts)
{
    if(amounts%2==0)
    {
        ptrScore+=amounts/2;
        //cout<<*ptrScore<<" ";
        //cout<<*(ptrScore+1)<<" ";
        return (*ptrScore+*(ptrScore+1))/2.0;
    }
    else
        return *(ptrScore+=amounts/2+1);
};
int studentScores[10] = {0}; // use rand() to generate values

int size = sizeof(studentScores)/sizeof(studentScores[0]);
//int size = 10;


int main()
{
    srand(time(NULL));
    for(int i=0;i<10;i++)
        studentScores[i]=rand()%101;

    for(int i=0;i<size;i++)
        for(int j=i+1;j<size;j++)
            if(studentScores[i]>studentScores[j])
            {
                int temp=studentScores[i];
                studentScores[i]=studentScores[j];
                studentScores[j]=temp;
            }

    float median = findMedianScore(studentScores,size);
    for(int i=0;i<size;i++)
        cout<<studentScores[i]<<" ";
    cout<<endl<<median;
}
