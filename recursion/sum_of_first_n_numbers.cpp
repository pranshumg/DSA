#include <bits/stdc++.h>

using namespace std;

/* Sum of first n numbers */

// Parameterized 
// TC - O(n), SC - O(n)
void sum_of_first_n_numbers(int sum, int n) {
    if (!n) {
        cout << sum << '\n';
        return;
    }
    sum_of_first_n_numbers(sum + n, n - 1);
}

// Functional
// TC - O(n), SC - O(n)
int sum_of_first_n_numbers(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sum_of_first_n_numbers(n - 1);
}