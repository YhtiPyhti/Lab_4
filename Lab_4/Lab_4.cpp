//вариант 7) 5*sin(x) = x;
//вариант 8)
//вариант 3) mt19937;
//вариант 3) 2^x mod 30539 = 28620;

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

void zad_2() {
    mt19937 gen(time(0));
    uniform_int_distribution<int> uid1(0, 100);

    int max2, min, max, n = 11, k = 0, N = 5, a = 10;;
    vector<int> arr, v;
    vector<vector<int>> mat(N, vector <int>(10));

    for (size_t i = 0; i < n; i++) {
        arr.push_back(uid1(gen));
        cout << arr[i] << " ";
    }

    min = distance(arr.begin(), min_element(arr.begin(), arr.end()));

    v = arr;
    sort(v.begin(), v.end());
    max2 = v[v.size() - 2];
    for (size_t i = 0; i < n; i++) {
        if (arr[i] == max2) {
            max = i;
        }
    }

    cout << endl;
    cout << "--------------------------" << endl;
    swap(arr[max], arr[min]);

    for (auto i : arr) {
        cout << i << " ";
    }

    cout << endl;
    cout << endl;
    cout << "|||||||||||||||||||||||||||||" << endl;
    cout << endl;

    v.clear();
    for (size_t i = 0; i < 5; i++) {
        v.push_back(uid1(gen));
        cout << v[i] << " ";
    }

    max = distance(v.begin(), max_element(v.begin(), v.end()));
    swap(v[max], v[0]);

    cout << endl;
    cout << "--------------------------" << endl;
    for (auto i : v) {
        cout << i << " ";
    }

    v.clear();
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < 10; j++) {
            mat[i][j] = a;
            a++;
        }
    }

    cout << endl;
    cout << endl;
    cout << "|||||||||||||||||||||||||||||" << endl;
    cout << endl;

    cout << "Вывод 1 " << endl;
    for (auto i : mat) {
        for (auto j : i) {
            k++;
            cout << j << " ";
            if (k == 10) {
                k = 0;
                cout << endl;
            }
        }
    }
    reverse(mat.begin(), mat.end());
    cout << "Вывод 2 " << endl;
    for (auto i : mat) {
        for (auto j : i) {
            k++;
            cout << j << " ";
            if (k == 10) {
                k = 0;
                cout << endl;
            }
        }
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

int main() {
    setlocale(LC_ALL, "Russian");
    //zad_1();
    //zad_2();
    //zad_3();
    //zad_4();
}