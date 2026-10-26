#include <bits/stdc++.h>

using namespace std;

/* Prime factors of a number */

bool is_prime(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (n / i != i) {
                cnt++;
            }
        }
    }
    return cnt == 2;
}

// TC - O(n), SC - O(k) where k is the no. of distinct prime factors
vector<int> prime_factors(int n) {
    vector<int> ans;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (is_prime(i)) {
                ans.push_back(i);
            }
            if (n / i != i) {
                if (is_prime(n / i)) {
                    ans.push_back(n / i);
                }
            }
        }
    }
    return ans;
}

// TC - O(sqrt(n)), SC - O(k) where k is the no. of distinct prime factors
vector<int> prime_factors(int n) {
    vector<int> ans;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            // Divide n by i repeatedly to remove this factor entirely
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    // If n > 1, the remaining part is a prime factor itself
    if (n > 1) {
        ans.push_back(n);
    }
    return ans;
}