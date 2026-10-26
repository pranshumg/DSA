#include <bits/stdc++.h>

using namespace std;

/* Count primes in a range L - R */
// https://leetcode.com/problems/count-primes/

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

// Method 1: Naive Approach
// TC - O((R - L + 1) * √n), SC - O(1)
int count_primes(int L, int R) {
    int cnt = 0;
    for (int i = L; i <= R; i++) {
        if (is_prime(i)) {
            cnt++;
        }
    }
    return cnt;
}

// Sieve of Eratosthenes
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// Method 2: Sieve (Direct Check)
// TC - O(N log log N + (R - L)), SC - O(N) where N = 1e6
int count_primes(int L, int R) {
    // Generate sieve up to the max possible value (e.g., 10^6)
    vector<bool> is_prime = sieve(int(1e6));
    int cnt = 0;
    for (int i = L; i <= R; i++) {
        if (is_prime[i]) {
            cnt++;
        }
    }
    return cnt;
}

// Method 3: Sieve with Prefix Sums (Optimal for multiple queries)
// TC - O(N log log N + N) for precomputation, O(1) per query
int count_primes(int L, int R) {
    // 1. Get Boolean Sieve
    vector<bool> is_prime = sieve(int(1e6));
    // 2. Convert to Prefix Sum Array
    // primes[i] will store the count of prime numbers from 0 to i
    vector<int> primes(int(1e6) + 1);
    int cnt = 0;
    for (int i = 0; i < int(primes.size()); i++) {
        if (is_prime[i]) {
            cnt++;
        }
        primes[i] = cnt;
    }
    // 3. Answer Query in O(1)
    return primes[R] - primes[L - 1];
}