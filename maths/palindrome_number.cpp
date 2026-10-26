#include <bits/stdc++.h>

using namespace std;

/* Palindrome number */
// https://leetcode.com/problems/palindrome-number/

// TC - O(log n), SC - O(1)
bool palindrome_number(int n) {
    int rev = 0, og = n;
    while (n) {
        int d = n % 10;
        rev = rev * 10 + d;
        n /= 10;
    }
    return og == rev;
}