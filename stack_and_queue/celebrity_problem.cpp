#include <bits/stdc++.h>

using namespace std;

/* the celebrity problem */

// TC - O(n * n), SC - O(n)
int celebrity(vector<vector<int>>& v, int n) {
  vector<int> knows(n), known(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (v[i][j] == 1) {
        knows[j]++;
        known[i]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (knows[i] == 0 && known[i] == n - 1) {
      return i;
    }
  }
  return -1;
}

// TC - O(n), SC - O(1)
int celebrity(vector<vector<int>>& v, int n) {
  int top = 0, down = n - 1;
  while (top < down) {
    if (v[top][down] == 1) {
      top++;
    } else if (v[down][top] == 1) {
      down--;
    } else {
      return -1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i == top) {
      continue;
    }
    if (v[top][i] == 1 || v[i][top] == 0) {
      return -1;
    }
  }
  return top;
}