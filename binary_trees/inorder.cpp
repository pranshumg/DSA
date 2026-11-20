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

    Node(int info, Node* left, Node* right) {
        this->info = info;
        this->left = left;
        this->right = right;
    }
};

// TC - O(n), SC - O(h)
void inorder_rec(Node* root) {
    if (!root) { 
        return;
    }
    inorder_rec(root->left);
    cout << root->info << ' ';
    inorder_rec(root->right);
}

// TC - O(n), SC - O(h)
void inorder(Node* root) {
    Node* cur = root;
    stack<Node*> sk;
    while (cur || !sk.empty()) {
        while (cur) {
            sk.push(cur);
            cur = cur->left;
        }
        cur = sk.top();
        sk.pop();
        cout << cur->info << ' ';
        cur = cur->right;
    }
}