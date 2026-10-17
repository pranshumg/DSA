#include <bits/stdc++.h>

using namespace std;

/* job sequencing problem */

// TC - O(n log n), SC - O(n)
int profit(vector<int>& deadline, vector<int>& profit) {
  vector<pair<int, int>> vp;
  for (int i = 0; i < int(deadline.size()); i++) {
    vp.emplace_back(deadline[i], profit[i]);
  }
  sort(vp.begin(), vp.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto& [dl, pt] : vp) {
    if (int(pq.size()) < dl) {
      pq.push(pt);
    } else if (!pq.empty() && pq.top() < pt) {
      pq.pop();
      pq.push(pt);
    }
  }
  int ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }
  return ans;
}

// TC - O(n log n), SC - O(n)
int profit(vector<int>& deadline, vector<int>& profit) {
  vector<pair<int, int>> vp;
  int mx = 0;
  for (int i = 0; i < int(deadline.size()); i++) {
    vp.emplace_back(deadline[i], profit[i]);
    mx = max(mx, deadline[i]);
  }
  sort(vp.begin(), vp.end(), [](auto& a, auto& b) {
    return a.second > b.second;
  });
  int ans = 0;
  vector<bool> vis(mx + 1, false);
  for (auto& [dl, pt] : vp) {
    for (int i = dl; i > 0; i--) {
      if (!vis[i]) {
        ans += pt;
        vis[i] = true; 
        break;
      }
    }
  } 
  return ans;
}