#include <bits/stdc++.h>

using namespace std;

/* Letter combinations */
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

void find_combination(int idx, string& digits, string& tmp, map<char, string>& mp, vector<string>& res) {
    if (idx >= int(digits.size())) {
        res.push_back(tmp);
        return;
    }
    for (char c : mp[digits[idx]]) {
        tmp.push_back(c);
        find_combination(idx + 1, digits, tmp, mp, res);
        tmp.pop_back();
    }
}

// TC - O(4^n * n), SC - O(n) where n is the length of the input digits
vector<string> letter_combinations(string digits) {
    map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> res;
    string tmp;
    find_combination(0, digits, tmp, mp, res);
    return res;
}