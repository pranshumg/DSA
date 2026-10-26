#include <bits/stdc++.h>

using namespace std;

/* GCD */

// TC - O(min(n, m)), SC - O(1)
int gcd(int n, int m) {
    for (int i = min(n, m); i >= 1; i--) {
        if (n % i == 0 && m % i == 0) {
            return i;
        }
    }
}