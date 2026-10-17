#include <bits/stdc++.h>

using namespace std;

/* jump game */
// https://leetcode.com/problems/jump-game/

// TC - O(n), SC - O(1)
int jump_game(vector<int>& v) {
  int mx = 0;
  for (int i = 0; i < int(v.size()); i++) {
    if (mx < i) {
      return false;
    }
    mx = max(mx, i + v[i]);
  }
  return true;
}