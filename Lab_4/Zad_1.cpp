#include <iostream>
#include <random>
#include <vector>  
#include <ctime>
#include <cstdint>

using namespace std;

double y(double x) {
    return 5 * sin(x * 3.14 / 180) - x;//y = 5sin(x) - x
}

double f(double x) {
    return 5 * cos(x * 3.14 / 180) - 1;//y' = 5cos(x) - 1
}

void MetPolDel(double a0, double b0, double& e) {
    int k = 0;
    double c = 0, a1 = a0, b1 = b0;
    while (abs(b1 - a1) >= e) {
        b0 = b1;
        a0 = a1;
        c = (a0 + b0) / 2;
        if (y(a0) * y(c) < 0) {
            a1 = a0;
            b1 = c;
        }
        else {
            a1 = c;
            b1 = b0;
        }
        k++;
        cout << "N_" << k;
        cout << " a: " << a1;
        cout << " b: " << b1;
        cout << " b-a: " << b1 - a1 << endl;
        cout << " --------------------------------------------------" << endl;
    }
}


void MetPrItr(double x0, double& e) {
    int k = 0;
    double x = 5 * sin(x0 * 3.14 / 180);
    while (abs(x - x0) >= e) {
        k++;
        x0 = x;
        x = 5 * sin(x0 * 3.14 / 180);
        cout << "N: " << k;
        cout << " Xn: " << x0;
        cout << " Xn+1: " << x;
        cout << " Xn - Xn+1: " << x - x0 << endl;
        cout << " --------------------------------------------------" << endl;
    }
}

void MetNut(double x0, double& e) {
    int k = 0;
    double x = x0 - y(x0) / f(x0);
    while (abs(x - x0) > e) {
        k++;
        x0 = x;
        x = x0 - y(x0) / f(x0);
        cout << "N:" << k;
        cout << " Xn: " << x0;
        cout << " Xn+1: " << x;
        cout << " Xn - Xn+1: " << x - x0 << endl;
        cout << " --------------------------------------------------" << endl;
    }
}


void zad_1() {
    double a0 = -1, b0 = 1, x = 2, e = 0.0001;
    MetPolDel(a0, b0, e);
    cout << "/////////////////////////////////////////////// " << endl;
    //MetNut(x, e);
    cout << "/////////////////////////////////////////////// " << endl;
    MetPrItr(x, e);
}