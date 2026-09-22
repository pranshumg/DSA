#include <bits/stdc++.h>

using namespace std;

/* stock span problem */
// https://leetcode.com/problems/online-stock-span/

// TC - O(n), SC - O(1)
class stock_spanner {
private:
  stack<pair<int, int>> sk;

public:
  stock_spanner() {

  }

  int next(int price) {
    int cnt = 1;
    while (!sk.empty() && sk.top().first <= price) {
      cnt += sk.top().second;
      sk.pop();
    }
    sk.emplace(price, cnt);
    return cnt;
  }
};