#include <iostream>
#include <random>
#include <vector>  
#include <ctime>
#include <cstdint>
using namespace std;

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