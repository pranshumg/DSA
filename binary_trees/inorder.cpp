#include <bits/stdc++.h>

using namespace std;

/* inorder traversal of binary tree */
// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
void inorder(Node* root) {
    if (!root) { 
        return;
    }
    inorder(root->left);
    cout << root->info << ' ';
    inorder(root->right);
}