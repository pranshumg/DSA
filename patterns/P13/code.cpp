#include <bits/stdc++.h>

using namespace std;

void P13(int n) {
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << num++ << " ";
        }
        cout << '\n';
    }
}