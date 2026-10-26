#include <bits/stdc++.h>

using namespace std;

void P22(int n) {
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            int top = i, left = j, right = 2 * n - 2 - j, down = 2 * n - 2 - i;
            cout << (n - min(min(top, down), min(left, right)));
        }
        cout << '\n';
    }
}