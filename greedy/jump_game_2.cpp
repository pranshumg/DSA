#include <bits/stdc++.h>

using namespace std;

/* jump game 2 */
// https://leetcode.com/problems/jump-game-ii/

// TC - O(n), SC - O(1)
int jump_game(vector<int>& v) {
  int cnt = 0, i = 0, j = 0;
  while (j < int(v.size())) {
    int mx = 0;
    for (int k = i; k <= j; k++) {
      mx = max(mx, k + v[k]);
    }
    i = j + 1;
    j = mx;
    cnt++;
  }
  return cnt;
}