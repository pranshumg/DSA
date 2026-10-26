#include <bits/stdc++.h>

using namespace std;

void P16(int n) {
    char c = 'A';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << c;
        }
        c++;
        cout << '\n';
    }
}