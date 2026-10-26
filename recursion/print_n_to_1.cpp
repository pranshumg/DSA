#include <bits/stdc++.h>

using namespace std;

/* Print n to 1 */

// TC - O(n), SC - O(n)
void print_n_to_1(int i, int n) {
    if (i > n) {
        return;
    }
    print_n_to_1(i + 1, n);
    cout << i << '\n';
}