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

void zad_3() {
    double Vn = 50, Nt, X = 0, Mx = 0, xsr = 0, S = 0, x = 0;
    vector<int> arr, arr1, arr2, Rt;
    vector<pair<int, int>> v;

    mt19937 gen(time(0));
    uniform_int_distribution<int> uid1(1, 100);

    /// <summary>
    /// 50
    /// </summary>
    for (size_t i = 0; i < Vn; i++) {
        arr.push_back(uid1(gen));
    }

    for (size_t j = 0; j < 10; j++){
        int N = 0;
        for (size_t i = 0; i < Vn; i++) {
            if (arr[i] > j*10 && arr[i] <= j*10 + 10) {
                N++;
            }
        }
        v.push_back(make_pair(j, N));//j - промежуток, N - количество попаданий
    }

    for (auto i : v){
        xsr += i.first * i.second;
    }
    xsr /= Vn;//Мат ожид

    for (auto i : v) {
        S += pow((xsr - i.first),2)*i.second;//дисперсия
    }
    S = S / (Vn - 1);
    S = sqrt(S);

    for (auto i : v) {
        auto u = (i.second - xsr) / S; //(x-xcp)/S
        auto q = 1 / sqrt(6.26) * exp( -(u * u) / 2);
        Nt = (arr.size() * 10) / S * q;//(n*h)/S * q(u)
        Rt.push_back(Nt);
        X += (i.second - Nt) * (i.second - Nt) / Nt;
    }

    cout << "X^2 = " << X << endl;
    cout << "Mx = " << xsr << endl;
    v.clear();

    /// <summary>
    /// 100
    /// </summary>
    Vn = 100;
    for (size_t i = 0; i < Vn; i++) {
        arr.push_back(uid1(gen));
    }

    for (size_t j = 0; j < 10; j++) {
        int N = 0;
        for (size_t i = 0; i < Vn; i++) {
            if (arr[i] > j * 10 && arr[i] <= j * 10 + 10) {
                N++;
            }
        }
        v.push_back(make_pair(j, N));//j - промежуток, N - количество попаданий
    }

    for (auto i : v) {
        xsr += i.first * i.second;
    }
    xsr /= Vn;//Мат ожид

    for (auto i : v) {
        S += pow((xsr - i.first), 2) * i.second;//дисперсия
    }
    S = S / (Vn - 1);
    S = sqrt(S);

    for (auto i : v) {
        auto u = (i.second - xsr) / S; //(x-xcp)/S
        auto q = 1 / sqrt(6.26) * exp(-(u * u) / 2);
        Nt = (arr.size() * 10) / S * q;//(n*h)/S * q(u)
        Rt.push_back(Nt);
        X += (i.second - Nt) * (i.second - Nt) / Nt;
    }

    cout << "X^2 = " << X << endl;
    cout << "Mx = " << xsr << endl;
    v.clear();


    /// <summary>
    /// 1000
    /// </summary>
    Vn = 1000;
    for (size_t i = 0; i < Vn; i++) {
        arr.push_back(uid1(gen));
    }

    for (size_t j = 0; j < 10; j++) {
        int N = 0;
        for (size_t i = 0; i < Vn; i++) {
            if (arr[i] > j * 10 && arr[i] <= j * 10 + 10) {
                N++;
            }
        }
        v.push_back(make_pair(j, N));//j - промежуток, N - количество попаданий
    }

    for (auto i : v) {
        xsr += i.first * i.second;
    }
    xsr /= Vn;//Мат ожид

    for (auto i : v) {
        S += pow((xsr - i.first), 2) * i.second;//дисперсия
    }
    S = S / (Vn - 1);
    S = sqrt(S);

    for (auto i : v) {
        auto u = (i.second - xsr) / S; //(x-xcp)/S
        auto q = 1 / sqrt(6.26) * exp(-(u * u) / 2);
        Nt = (arr.size() * 10) / S * q;//(n*h)/S * q(u)
        Rt.push_back(Nt);
        X += (i.second - Nt) * (i.second - Nt) / Nt;
    }

    cout << "X^2 = " << X << endl;
    cout << "Mx = " << xsr;
    v.clear();
}