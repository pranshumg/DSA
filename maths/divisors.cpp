#include <bits/stdc++.h>

using namespace std;

/* Divisors */

// TC - O(n)
vector<int> divisors(int n) {
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
        }
    }
    return ans;
}

// TC - O(sqrt(n))
vector<int> divisors(int n) {
    vector<int> ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            // If the pair divisor is different, push it too
            if (n / i != i) {
                ans.push_back(n / i);
            }
        }
    }
    return ans;
}