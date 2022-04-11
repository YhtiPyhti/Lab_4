//вариант 7) 5*sin(x) = x;
//вариант 8)
//вариант 3) mt19937;
//вариант 3) 2^x mod 30539 = 28620;

#include <iostream>
#include <random>
#include <vector>  
#include <ctime>
#include <cstdint>
#include "Header.h"

using namespace std;

double y(double x);

double f(double x);

void MetPolDel(double a0, double b0, double& e);

void MetPrItr(double x0, double& e);

void MetNut(double x0, double& e);

void zad_3();

void zad_2();

void zad_1();

void zad_4() {
    int a = 2, N = 0, m = 30539, t0 = 0, r = 28620, t = 0, b = a;
    t0 = b % m;
    while (t % m != r) {
        t = b % m;
        b = t * t0;
        N++;
    }
    cout << N;
}
int main() {
    setlocale(LC_ALL, "Russian");
    //zad_1();
    //zad_2();
    //zad_3();
    //zad_4();
}