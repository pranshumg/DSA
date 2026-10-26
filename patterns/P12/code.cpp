#include <bits/stdc++.h>

using namespace std;

void P12(int n) {
    int x;
    for (int i = 0; i < n; i++) {
        // Ascending numbers
        for (int j = 0; j <= i; j++) {
            cout << j + 1;
            x = j + 1;
        }
        // Spaces in the middle
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        // Descending numbers
        for (int j = 0; j <= i; j++, x--) {
            cout << x;
        }
        cout << '\n';
    }
}