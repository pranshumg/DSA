#include <bits/stdc++.h>

using namespace std;

/* minimum number of platforms required in a railway station */

// TC - O(n log n), SC - O(n)
int platforms(vector<int>& a, vector<int>& d) {
  vector<pair<int, int>> vp;
  for (int i = 0; i < int(a.size()); i++) {
    vp.emplace_back(a[i], d[i]);
  }
  sort(vp.begin(), vp.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  int ans = 0;
  for (int i = 0; i < int(vp.size()); i++) {
    while (!pq.empty() && pq.top() < vp[i].first) {
      pq.pop();
    }
    pq.push(vp[i].second);
    ans = max(ans, int(pq.size()));
  }
  return ans;
}

// TC - O(n log n), SC - O(n)
int platforms(vector<int>& a, vector<int>& d) {
  vector<pair<int, int>> vp;
  for (int i = 0; i < int(a.size()); i++) {
    vp.emplace_back(a[i], 1);
    vp.emplace_back(d[i], -1);
  }
  sort(vp.begin(), vp.end(), [](auto& a, auto& b) {
    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first < b.first;
  });
  int ans = 0, cnt = 0;
  for (auto& [x, y] : vp) {
    y == 1 ? cnt++ : cnt--;
    ans = max(ans, cnt);
  }
  return ans;
}

// TC - O(n log n), SC - O(1)
int platforms(vector<int>& a, vector<int>& d) { 
  sort(a.begin(), a.end());
  sort(d.begin(), d.end());
  int i = 0, j = 0, ans = 0, cnt = 0;
  while (i < int(a.size())) {
    if (a[i] > d[j]) {
      cnt--;
      j++;
    } else {
      cnt++;
      i++;
    }
    ans = max(ans, cnt);
  }
  return ans;
}