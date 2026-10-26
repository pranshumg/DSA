#include <bits/stdc++.h>

using namespace std;

/* Armstrong number */
// https://leetcode.com/problems/armstrong-number/

// TC - O(log n)
bool armstrong_number(int n) {
    int cnt = int(log10(n) + 1), sum = 0, og = n;
    while (n) {
        int d = n % 10;
        sum += pow(d, cnt);
        n /= 10;
    }
    return og == sum;
}