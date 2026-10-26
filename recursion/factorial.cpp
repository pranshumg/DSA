#include <bits/stdc++.h>

using namespace std;

/* Factorial */

// Parameterized
// TC - O(n), SC - O(n)
void factorial(int fact, int n) {
    if (!n) {
        cout << fact << '\n';
        return;
    }
    factorial(fact * n, n - 1);
}

// Functional
// TC - O(n), SC - O(n)
int factorial(int n) {
    if (!n) {
        return 1;
    }
    return n * factorial(n - 1);
}