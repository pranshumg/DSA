#include <bits/stdc++.h>

using namespace std;

/* Fibonacci Number */
// https://leetcode.com/problems/fibonacci-number/

// TC - O(2^n), SC - O(n)
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}