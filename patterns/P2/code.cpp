#include <bits/stdc++.h>

using namespace std;

void P2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << '\n';
    }
}