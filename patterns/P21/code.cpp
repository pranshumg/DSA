#include <bits/stdc++.h>

using namespace std;

void P21(int n) {
    if (n == 1) {
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
    } else {
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << '\n';
        for (int i = 0; i < n - 2; i++) {
            cout << "*";
            for (int j = 0; j < n - 2; j++) {
                cout << " ";
            }
            cout << "*" << '\n';
        }
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
    }
}