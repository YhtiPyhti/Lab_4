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
    int n = (int)sqrt(m) + 1, an = 1, t = 0;

    for (int i = 0; i < n; ++i)
        an = (an * a) % m; // a^n mod m

    t = an;
    for (int i = 1; i <= n; ++i) {//шаги младенца
        if (vals.count(t) == 0) vals[t] = i; // записывается наименьший i
        t = (t * an) % m;
    }

    t = b;
    for (int i = 0; i <= n; ++i) {
        if (vals.count(t) != 0) {
            int ans = vals[t] * n - i;
            if (ans < m)
                return ans;
        }
        t = (t * a) % m;
    }

    return -1;
}
int main() {
    setlocale(LC_ALL, "Russian");
    //zad_1();
    //zad_2();
    //zad_3();
    cout << zad_4 (2, 28620, 30539);
}