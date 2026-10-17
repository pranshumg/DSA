#include <bits/stdc++.h>

using namespace std;

/* lemonade change */
// https://leetcode.com/problems/lemonade-change/

// TC - O(n), SC - O(1)
bool lemonade_change(vector<int>& v) {
  int five = 0, ten = 0;
  for (int i = 0; i < int(v.size()); i++) {
    if (v[i] == 5) {
      five++;
    } else if (v[i] == 10) {
      if (five) {
        five--;
      } else {
        return false;
      }
      ten++;
    } else {
      if (ten && five) {
        ten--;
        five--;
      } else if (five > 2) {
        five -= 3;
      } else {
        return false;
      }
    }
  }
  return true;
}