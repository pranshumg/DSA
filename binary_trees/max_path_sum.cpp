#include <bits/stdc++.h>

using namespace std;

/* maximum path sum of binary tree */
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

class Node {
public:
    int info;
    Node* left;
    Node* right;

    Node(int info) {
        this->info = info;
        this->left = this->right = nullptr;
    }
};

int rec(Node* root, int& ans) {
    if (!root) {
        return 0;
    }
    int l = rec(root->left, ans);
    int r = rec(root->right, ans);
    ans = max(ans, root->info + max({0, l, r, l + r}));
    return root->info + max({0, l, r});
}

// TC - O(n), SC - O(h)
int max_path_sum(Node* root) {
    int ans = INT32_MIN;
    rec(root, ans);
    return ans;
}