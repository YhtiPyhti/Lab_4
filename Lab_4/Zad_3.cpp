#include <iostream>
#include <random>
#include <vector>  
#include <ctime>
#include <cstdint>
#include "Header.h"
using namespace std;
void zad_3() {
    double Vn = 50, Vexp = 1, Nt = 0.1 * 10, x = 0, r = 0;
    int k = 0, max = 0, max1 = 0, max2 = 0, N = 0;
    vector<int> arr, arr1, arr2, v;

    mt19937 gen(time(0));
    uniform_int_distribution<int> uid1(1, 100);

    for (size_t i = 0; i < 50; i++) {
        arr.push_back(uid1(gen));
    }

    for (size_t j = 0; j < 10; j++){
        N = 0;
        for (size_t i = 0; i < 50; i++) {
            if (arr[i] > j*10 && arr[i] < j*10 + 10) {
                N++;
            }
        }
        v.push_back(N);
    }
    
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : v) {
        r = i / 50;
        x += pow((r - Nt), 2) / Nt;
    }
    cout << "x^2 = " << x;
    v.clear();

    for (size_t i = 0; i < 100; i++) {
        arr1.push_back(uid1(gen));
    }


    for (size_t j = 0; j < 10; j++) {
        N = 0;
        for (size_t i = 0; i < 100; i++) {
            if (arr1[i] > j * 10 && arr1[i] < j * 10 + 10) {
                N++;
            }
        }
        v.push_back(N);
    }

    cout << endl;
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : v) {
        r = i / 100;
        x += pow((r - Nt), 2) / Nt;
    }
    cout << "x^2 = " << x;
    v.clear();

    for (size_t i = 0; i < 1000; i++) {
        arr2.push_back(uid1(gen));
    }


    for (size_t j = 0; j < 10; j++) {
        N = 0;
        for (size_t i = 0; i < 1000; i++) {
            if (arr2[i] > j * 10 && arr2[i] < j * 10 + 10) {
                N++;
            }
        }
        v.push_back(N);
    }

    cout << endl;
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : v) {
        r = i / 1000;
        x += pow((r - Nt), 2) / Nt;
    }
    cout << "x^2 = " << x;

}