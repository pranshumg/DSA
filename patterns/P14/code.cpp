#include <bits/stdc++.h>

using namespace std;

void P14(int n) {
    for (int i = 0; i < n; i++) {
        char c = 'A';
        for (int j = 0; j <= i; j++) {
            cout << c++;
        }
        cout << '\n';
    }
}