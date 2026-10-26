#include <bits/stdc++.h>

using namespace std;

void P4(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << i + 1;
        }
        cout << '\n';
    }
}