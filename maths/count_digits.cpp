#include <bits/stdc++.h>

using namespace std;

/* Count digits */

// TC - O(log n)
int count_digits(int n) {
    int cnt = 0;
    if (!n) {
        return 1;
    }
    n = abs(n);
    while (n) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

// TC - O(1)
int count_digits(int n) {
    string s = to_string(n);
    return n < 0 ? int(s.size()) - 1 : int(s.size());
}

// TC - O(1)
int count_digits(int n) {
    n = abs(n);
    return n ? int(log10(n) + 1) : 1;
}