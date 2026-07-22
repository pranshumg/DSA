#include <bits/stdc++.h>

using namespace std;

/* Largest subarray with sum 0 */

// Brute 
// TC - O(n * n * n), SC - O(1)
int largest_subarray(vector<int>& v, int n) {
  int largest = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int sum = 0;
      for (int k = i; k <= j; k++) {
        sum += v[k];
      }
      if (sum == 0) {
        largest = max(largest, j - i + 1);
      }
    }
  }
  return largest;
}

// Better 
// TC - O(n * n), SC - O(1)
int largest_subarray(vector<int>& v, int n) {
  int largest = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += v[j];
      if (sum == 0) {
        largest = max(largest, j - i + 1);
      }
    }
  }
  return largest;
}

// Optimal 
// TC - O(n), SC - O(n)
int largest_subarray(vector<int>& v, int n) {
  int largest = 0, sum = 0;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    sum += v[i];
    if (sum == 0) {
      largest = i + 1;
    }  
    if (mp.find(sum) != mp.end()) {
      largest = max(largest, i - mp[sum]);
    } else {
      mp[sum] = i;
    }
  }
  return largest;
}