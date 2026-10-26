#include <bits/stdc++.h>

using namespace std;

void P10(int n) {
    // Upper triangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << '\n';
    }
    // Lower inverted triangle
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            cout << "*";
        }
        cout << '\n';
    }
}