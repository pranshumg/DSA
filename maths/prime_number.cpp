#include <bits/stdc++.h>

using namespace std;

/* Prime number */

// TC - O(n), SC - O(1)
bool is_prime(int n) {
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// TC - O(sqrt(n)), SC - O(1)
bool is_prime(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (n / i != i) {
                cnt++;
            }
        }
        if (cnt > 2) break;
    }
    return cnt == 2;
}