#include <bits/stdc++.h>

using namespace std;

/* Euclidean algorithm */

// TC - O(log min(n, m)), SC - O(1)
int euclidean_algorithm(int n, int m) {
    while (n > 0 && m > 0) {
        n > m ? n %= m : m %= n;
    }
    return (n == 0 ? m : n);
}