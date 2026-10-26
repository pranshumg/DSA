#include <bits/stdc++.h>

using namespace std;

/* Rotate String */
// https://leetcode.com/problems/rotate-string/

// TC - O(n), SC - O(n)
bool rotate_string(string s, string t) {
    if (int(s.size()) != int(t.size())) {
        return false;
    }
    return (s + s).find(t) != string::npos;
}