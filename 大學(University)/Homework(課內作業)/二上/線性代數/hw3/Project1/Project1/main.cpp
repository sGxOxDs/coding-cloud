//
// 快速傅立葉變換 Fast Fourier Transform
// By rappizit@yahoo.com.cn
// 2007-07-20
// 版本 2.0
// 改進了《算法導論》的算法，旋轉因子取 ωn-kj   (ωnkj 的共軛復數)
// 且只計算 n / 2 次，而未改進前需要計算 (n * lg n) / 2 次。
//


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

//const int N = 1024;
const int N = 8192;
//const double PI = 3.1416;
const double PI = 3.14159265358979323846;

inline void swap(double& a, double& b)
{
    double t;
    t = a;
    a = b;
    b = t;
}

void bitrp(double xreal[], double ximag[], int n)
{
    // 位反轉置換 Bit-reversal Permutation
    int i, j, a, b, p;

    for (i = 1, p = 0; i < n; i *= 2)
    {
        p++;
    }
    for (i = 0; i < n; i++)
    {
        a = i;
        b = 0;
        for (j = 0; j < p; j++)
        {
            b = (b << 1) + (a & 1);     // b = b * 2 + a % 2;
            a >>= 1;         // a = a / 2;
        }
        if (b > i)
        {
            swap(xreal[i], xreal[b]);
            swap(ximag[i], ximag[b]);
        }
    }
}

void FFT(double xreal[], double ximag[], int n)
{
    // 快速傅立葉變換，將復數 x 變換后仍保存在 x 中，xreal, ximag 分別是 x 的實部和虛部
    double wreal[N / 2], wimag[N / 2], treal, timag, ureal, uimag, arg;
    int m, k, j, t, index1, index2;

    bitrp(xreal, ximag, n);

    // 計算 1 的前 n / 2 個 n 次方根的共軛復數 W'j = wreal [j] + i * wimag [j] , j = 0, 1,   , n / 2 - 1
    arg = -2 * PI / n;
    treal = cos(arg);
    timag = sin(arg);
    wreal[0] = 1.0;
    wimag[0] = 0.0;
    for (j = 1; j < n / 2; j++)
    {
        wreal[j] = wreal[j - 1] * treal - wimag[j - 1] * timag;
        wimag[j] = wreal[j - 1] * timag + wimag[j - 1] * treal;
    }

    for (m = 2; m <= n; m *= 2)
    {
        for (k = 0; k < n; k += m)
        {
            for (j = 0; j < m / 2; j++)
            {
                index1 = k + j;
                index2 = index1 + m / 2;
                t = n * j / m;     // 旋轉因子 w 的實部在 wreal [] 中的下標為 t
                treal = wreal[t] * xreal[index2] - wimag[t] * ximag[index2];
                timag = wreal[t] * ximag[index2] + wimag[t] * xreal[index2];
                ureal = xreal[index1];
                uimag = ximag[index1];
                xreal[index1] = ureal + treal;
                ximag[index1] = uimag + timag;
                xreal[index2] = ureal - treal;
                ximag[index2] = uimag - timag;
            }
        }
    }
}

void FFT_test(const char inputfile[])
{
    //char inputfile[] = "ex2.csv";     // 從文件 input.txt 中讀入原始數據
    int n, i;

    fstream fin(inputfile, ios::in);
    if (!fin)
    {
        printf("Cannot open fin file. ");
        exit(1);
    }

    int data_case = 1;
    string s;
    while (getline(fin, s))
    {
        stringstream ss;
        ss << s;
        char c[100];
        double xreal[N] = {}, ximag[N] = {};
        i = 0;
        while (ss.getline(c, 100, ','))
        {
            xreal[i] = atof(c);
            ximag[i] = 0;
            i++;
        }
        n = i;
        FFT(xreal, ximag, n);
        if (data_case > 1)cout << "\n";
        cout << "Data " << data_case++ << " : "<<"\n";
        for (i = 0; i < n; i++)
        {
            //printf("%8.4f %8.4f\n", xreal[i], ximag[i]);
            cout << setprecision(4) << fixed;
            cout << xreal[i] << " " << ximag[i] << "\n";
        }
        //cout << endl;
    }
    fin.close();
}

int main(int argc, char* argv[])
{
    //FFT_test("ex2.csv");
    FFT_test(argv[1]);
    return 0;
}