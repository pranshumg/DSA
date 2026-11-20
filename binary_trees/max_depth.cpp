#include <bits/stdc++.h>

using namespace std;

/* maximum depth of binary tree */
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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

int rec(Node* root, int cnt) {
    if (!root) {
        return cnt;
    }
    return max(rec(root->left, cnt + 1), rec(root->right, cnt + 1));
}

// Top-down
// TC - O(n), SC - O(n)
int max_depth(Node* root) {
    return rec(root, 0);
}

// Bottom-up
// TC - O(n), SC - O(n)
int max_depth(Node* root) {
    if (!root) {
        return 0;
    }
    return 1 + max(max_depth(root->left), max_depth(root->right));
}