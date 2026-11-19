#include <bits/stdc++.h>

using namespace std;

/* preorder traversal of binary tree */
// https://leetcode.com/problems/binary-tree-preorder-traversal/

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

// TC - O(n), SC - O(h)
void preorder(Node* root) {
    if (!root) { 
        return;
    }
    cout << root->info << ' ';
    preorder(root->left);
    preorder(root->right);
}