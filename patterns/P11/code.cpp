#include <bits/stdc++.h>

using namespace std;

void P11(int n) {
    int num;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            num = 1;
        } else {
            num = 0;
        }
        for (int j = 0; j <= i; j++) {
            cout << num;
            num = 1 - num;
        }
        cout << '\n';
    }
}