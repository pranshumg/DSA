#include <bits/stdc++.h>

using namespace std;

/* check for balanced binary tree */
// https://leetcode.com/problems/balanced-binary-tree/

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

int rec(Node* root, bool& b) {
    if (!root) {
        return 0;
    }
    int l = rec(root->left, b);
    int r = rec(root->right, b);
    if (abs(r - l) > 1) {
        b = false;
    }
    return 1 + max(l, r);
}

// TC - O(n), SC - O(h)
bool is_balanced(Node* root) {
    bool b = true;
    rec(root, b);
    return b;
}