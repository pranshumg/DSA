#include <bits/stdc++.h>

using namespace std;

/* Check if a given string is palindrome */
// https://leetcode.com/problems/valid-palindrome/

// TC - O(n), SC - O(n)
bool is_palindrome(string& s, int l, int r) {
    if (l >= r) {
        return true;
    }
    if (s[l] != s[r]) {
        return false;   
    }
    return is_palindrome(s, l + 1, r - 1);
}