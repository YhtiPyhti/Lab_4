//вариант 7) 5*sin(x) = x;
//вариант 8)
//вариант 3) mt19937;
//вариант 3) 2^x mod 30539 = 28620;

#include <iostream>
#include <random>
#include <vector>
#include <map>
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

int zad_4(int a, int b, int m) { // a-numb, b - остаток, m - делитель 
    map<int, int> vals;
    int n = (int)sqrt(m) + 1, g = 1, t = 0;

    for (int i = 0; i < n; i++)
        g = (g * a) % m; // a^n mod m

    t = g;

    for (int i = 1; i <= n; i++) {//шаги младенца g^n,g^2n,...,g^nn
        if (vals.count(t) == 0) vals[t] = i; // записывается наименьший i
        t = (t * g) % m;
    }

    t = b;

    for (int i = 0; i <= n; i++) {
        if (vals.count(t) != 0) {
            int ans = vals[t] * n - i;// x = n*i-j
            return ans % m;
        }
        t = (t * a) % m; //шаги гиганта b*g ,b*g^2,...,b*g^n-1
    }
    return -1;
}
int main() {
    setlocale(LC_ALL, "Russian");
    //zad_1();
    //zad_2();
    zad_3();
    //cout << zad_4 (2, 28620, 30539);
}