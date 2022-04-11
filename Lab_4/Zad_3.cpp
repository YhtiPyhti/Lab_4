#include <iostream>
#include <random>
#include <vector>  
#include <ctime>
#include <cstdint>
#include "Header.h"
using namespace std;
void zad_3() {
    double Vn = 50, Vexp = 1, x = 0, x1 = 0, x2 = 0, MatOzOz = 50, MatOzReal = 0;
    int k = 0, max = 0, max1 = 0, max2 = 0;
    vector<int> arr, arr1, arr2;
    mt19937 gen(time(0));
    uniform_int_distribution<int> uid1(1, 100);
    for (size_t i = 0; i < 50; i++) {
        arr.push_back(uid1(gen));
        x += (Vn - Vexp) * (Vn - Vexp) / Vexp;
    }
    for (size_t i = 0; i < 100; i++) {
        arr1.push_back(uid1(gen));;
        x1 += (Vn - Vexp) * (Vn - Vexp) / Vexp;
    }
    for (size_t i = 0; i < 1000; i++) {
        arr2.push_back(uid1(gen));
        x2 += (Vn - Vexp) * (Vn - Vexp) / Vexp;
    }

    for (size_t i = 0; i < 49; i++) {
        if (arr[i] == arr[i + 1]) {
            k++;
            if (k > max) max = k;
        }
        else k = 0;
    }
    for (size_t i = 0; i < 99; i++) {
        if (arr1[i] == arr1[i + 1]) {
            k++;
            if (k > max1) max1 = k;
        }
        else k = 0;
    }
    for (size_t i = 0; i < 999; i++) {
        if (arr2[i] == arr2[i + 1]) {
            k++;
            if (k > max2) max2 = k;
        }
        else k = 0;
    }
    cout << x << " " << max << " " << x1 << " " << max1 << " " << x2 << " " << max2;
}