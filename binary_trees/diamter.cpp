#include <bits/stdc++.h>

using namespace std;

/* diameter of a binary tree */
// https://leetcode.com/problems/diameter-of-binary-tree/description/

class Node {
public:
    int info;
    Node* left;
    Node* right;

    Node(int info) {
        this->info = info;
        this->left = this->right = nullptr;
    }

    Node(int info, Node* left, Node* right) {
        this->info = info;
        this->left = left;
        this->right = right;
    }
};

int rec(Node* root, int& ans) {
    if (!root) {
        return 0;
    }
    int l = rec(root->left, ans);
    int r = rec(root->right, ans);
    ans = max(ans, l + r);
    return 1 + max(l, r);
}

// TC - O(n), SC - O(h)
int diameter(Node* root) {
    int ans = 0;
    rec(root, ans);
    return ans;
}