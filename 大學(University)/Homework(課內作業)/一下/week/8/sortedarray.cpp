#include <iostream>
#include "sortedarray.h"
using namespace std;

template <typename T>
Array <T>::Array(int s)
{
    ArrayPtr = new T[s]();
    Size = 0;
    Res = s;
}

template <typename T>
Array <T>::~Array()
{
    if (ArrayPtr != nullptr)
        delete[] ArrayPtr;
}

template <typename T>
void Array <T>::setValue(int index, T value)
{
    ArrayPtr[index] = value;
}

template <typename T>
T Array <T>::getValue(int index)
{
    return ArrayPtr[index];
}

template <typename T>
bool isgreater(T left, T right)
{
    if (left > right)
        return true;
    return false;
}

template <typename T>
void SortedArray<T>::addValue(T t)
{
    this->ArrayPtr[this->Size] = t;
    this->Size++;
    for (int i = 0; i < this->Size; i++)
        for (int j = i + 1; j < this->Size; j++)
            if (isgreater(this->ArrayPtr[j], this->ArrayPtr[i]))
            {
                T temp = this->ArrayPtr[i];
                this->ArrayPtr[i] = this->ArrayPtr[j];
                this->ArrayPtr[j] = temp;
            }
}

template class Array<int>;
template class Array<float>;
template class Array<string>;
template class SortedArray<int>;
template class SortedArray<float>;
template class SortedArray<string>;

template<> bool isgreater(string left, string right)
{    if (left > right)
        return true;
    return false;}