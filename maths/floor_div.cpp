#include <bits/stdc++.h>

using namespace std;

/* Floor division */

// TC - O(1), SC - O(1)
int64_t floor_div(int64_t a, int64_t b) {
    assert(b != 0);
    if (b < 0) {
        a = -a, b = -b;
    }
    if (a >= 0) {
        return a / b;
    }
    return -((-a + b - 1) / b);
}