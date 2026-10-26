#include <bits/stdc++.h>

using namespace std;

/* Print name n times */

// TC - O(n), SC - O(n)
void print_name_n_times(string& name, int n) {
    if (!n) {
        return;
    }
    print_name_n_times(name, n - 1);
    cout << name << '\n';
}