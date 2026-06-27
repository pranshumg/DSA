#include <bits/stdc++.h>

using namespace std;

/* Largest odd number in string */
// https://leetcode.com/problems/largest-odd-number-in-string/

// TC - O(n), SC - O(n)
string largest_odd_number(string s) {
    for (int i = int(s.size()) - 1; i >= 0; i--) {
        if ((s[i] - '0') & 1) {
            return s.substr(0, i + 1);
        }
    }
    return "";
}