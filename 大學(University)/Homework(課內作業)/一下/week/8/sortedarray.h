// 1083339 template function
#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H
#include <iostream>

using namespace std;

template <typename T>
class Array {
    public:
        Array(int s);
        ~Array();
        void setValue(int index, T value);
        T getValue(int index);
    protected:
        int Size;
        int Res;
        T *ArrayPtr;
};

template <typename T>
class SortedArray :public Array<T> {
    public:
        SortedArray(int s) :Array<T>(s) {};
        void addValue(T t);
};

#endif // SORTEDARRAY_H
