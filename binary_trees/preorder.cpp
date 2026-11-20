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

    Node(int info, Node* left, Node* right) {
        this->info = info;
        this->left = left;
        this->right = right;
    }
};

// TC - O(n), SC - O(h)
void preorder_rec(Node* root) {
    if (!root) { 
        return;
    }
    cout << root->info << ' ';
    preorder_rec(root->left);
    preorder_rec(root->right);
}

// TC - O(n), SC - O(n)
void preorder(Node* root) {
    Node* cur = root;
    stack<Node*> sk;
    while (cur || !sk.empty()) {
        while (cur) {
            cout << cur->info << ' ';
            sk.push(cur);
            cur = cur->left;
        }
        cur = sk.top();
        sk.pop();
        cur = cur->right;
    }
}