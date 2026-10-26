#include <bits/stdc++.h>

using namespace std;

/* Reverse number */
// https://leetcode.com/problems/reverse-integer/

// TC - O(log n)
int reverse(int n) {
    int rev = 0;
    while (n) {
        int d = n % 10;
        rev = rev * 10 + d;
        n /= 10;
    }
    return rev;
}