#include <bits/stdc++.h>

using namespace std;

/* Print 1 to n */

// TC - O(n), SC - O(n)
void print_1_to_n(int n) {
    if (!n) {
        return;
    }
    print_1_to_n(n - 1);
    cout << n << '\n';
}