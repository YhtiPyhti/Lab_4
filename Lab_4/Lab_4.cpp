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
#include <algorithm>
#include <cmath>
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

int zad_4_a(int a, int b, int m) { // a-numb, b - остаток, m - делитель 
    map<int, int> vals;
    int n = (int)sqrt(m) + 1, g = 1, t = 0;
    vector<int> S = { 2,3,5,53 };
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
vector<int> find(int n) {
    vector<int> v;
    int div = 2;
    while (n > 1) {
        while (n % div == 0) {
            n = n / div;
            v.push_back(div);
        }
        div++;
    }
    return v;
}

int invert(int a, int m){
    int v1 = a, t = 0, t0 = a % m;
    for (int i = 1; i <= m-1; i++) {
        t = (a*i) % m;
        if (t == 1) {
            return i;
        }
    }
}
void zad_4_b(int g, int q, int n) { // g-numb, q - остаток, n - делитель 
    int k = 5000, y = g, i = 0, t = 0, t0 = g % n, U1=0, U2=0, U3=0, U4=0,a=0,b=0,c=0,d=0, x=0;
    vector<int> S = { 2,3,5 }, ter;
    vector<pair<int,int>> re;
    for (i = 1; i <= k; i++) {
        t = y % n;
        y = t * t0;
        ter = find(t);
        if (ter[ter.size() - 1] <= S[S.size() - 1]) {
            re.push_back(pair<int, int>(i, t));
        }
        ter.clear();
    }

    a = 926;//U3+U3
    b = 1852;//4*U3
    c = 2414;//U3+2U2
    d = 3904;//4U2
    U1 = 1;
    U3 = b/4;
    U2 = invert(5 , n);
    U2 = 975 * U2 % n;
    
    t0 = q % n;
    t = 1;
    y = g;
    for (i = 1; i <= 1500; i++) {
        t = (t * y) % n;
        t0 = q * t % n;
        ter = find(t0);
        if ((ter[ter.size() - 1] <= S[S.size() - 1]) and (ter.size() >= 2)) {
            break;
        }
        ter.clear();
    }
    for (auto i : ter) {
        if (i == 2) x += U1;
        if (i == 3) x += U2;
        if (i == 5) x += U3;
    }
    x = (x - i) % (n-1);//?
    cout << x;

}


int main() {
    setlocale(LC_ALL, "Russian");
    //zad_1();
    //zad_2();
    //zad_3();
    //cout << zad_4_a (2, 28620, 30539);
    zad_4_b(2, 28620, 30539);
}