#include <bits/stdc++.h>

using namespace std;

/* Reverse pairs */
// https://leetcode.com/problems/reverse-pairs/

// Brute 
// TC - O(n * n), SC - O(1)
int reverse_pairs(vector<int>& v, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > 2 * v[j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

void merge(vector<int>& v, int low, int mid, int high) {
    vector<int> tmp;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (v[i] <= v[j]) {
            tmp.push_back(v[i++]);
        } else {
            tmp.push_back(v[j++]);
        }
    }
    while (i <= mid) {
        tmp.push_back(v[i++]);
    }
    while (j <= high) {
        tmp.push_back(v[j++]);
    }   
    for (int i = low; i <= high; i++) {
        v[i] = tmp[i - low];
    }
}

int count_pairs(vector<int>& v, int low, int mid, int high) {
    int j = mid + 1, cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (j <= high && v[i] > 2 * v[j]) {
            ++j;
        }
        cnt += j - (mid + 1);
    }
    return cnt;
}

int merge_sort(vector<int>& v, int low, int high) {
    int cnt = 0;
    if (low >= high) {
        return cnt;
    }
    int mid = low + (high - low) / 2;
    cnt += merge_sort(v, low, mid);
    cnt += merge_sort(v, mid + 1, high);
    cnt += count_pairs(v, low, mid, high);
    merge(v, low, mid, high);
    return cnt;
}

// Optimal 
// TC - O(n log n), SC - O(n)
int reverse_pairs(vector<int>& v, int n) {
    return merge_sort(v, 0, n - 1);
}