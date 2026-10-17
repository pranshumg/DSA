#include <bits/stdc++.h>

using namespace std;

/* swap two numbers */

// TC - O(1), SC - O(1)
void Swap(int& a, int& b) {
  if (&a != &b) {
    a ^= b;
    b ^= a;
    a ^= b;
  }
}