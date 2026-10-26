#include <bits/stdc++.h>

using namespace std;

void P17(int n) {
    for (int i = 0; i < n; i++) {
        char c1 = 'A';
        // Print leading spaces
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        // Print ascending letters
        for (int j = 0; j <= i; j++) {
            cout << c1++;
        }
        // Print descending letters
        for (char c2 = c1 - 2; c2 >= 'A'; c2--) {
            cout << c2;
        }
        cout << '\n';
    }
}