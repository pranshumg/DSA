#include <bits/stdc++.h>

using namespace std;

/* postorder traversal of binary tree */
// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
void postorder(Node* root) {
    if (!root) { 
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->info << ' ';
}