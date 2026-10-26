#include <bits/stdc++.h>

using namespace std;

/* Ceil division */

// TC - O(1), SC - O(1)
int64_t ceil_div(int64_t a, int64_t b) {
    assert(b != 0);
    if (b < 0) {
        a = -a, b = -b;
    }
    if (a >= 0) {
        return (a + b - 1) / b;
    }
    return a / b;
}