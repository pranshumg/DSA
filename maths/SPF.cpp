#include <bits/stdc++.h>

using namespace std;

/* Smallest Prime Factor (SPF) using Sieve */

// TC - O(n log log n), SC - O(n)
vector<int> SPF(int n) {
    vector<int> ans(n + 1);
    // Initialize SPF[i] = i
    for (int i = 0; i < int(ans.size()); i++) {
        ans[i] = i;
    }
    // Iterate from 2 to sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        // If ans[i] == i, then i is prime
        if (ans[i] == i) {
            // Mark SPF for all multiples of i
            for (int j = i * i; j <= n; j += i) {
                // Only update if it hasn't been touched yet (ans[j] == j)
                // This ensures we record the *smallest* prime factor
                if (ans[j] == j) {
                    ans[j] = i;
                }
            }
        }
    }
    return ans;
}

// TC - O(log n), SC - O(n)
vector<int> prime_factors(int n) {
    vector<int> ans;
    // Calculate SPF table up to n
    vector<int> spf = SPF(n);
    while (n > 1) {
        ans.push_back(spf[n]);
        n /= spf[n];
    }
    return ans;
}