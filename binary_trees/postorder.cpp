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

    Node(int info, Node* left, Node* right) {
        this->info = info;
        this->left = left;
        this->right = right;
    }
};

// TC - O(n), SC - O(h)
void postorder_rec(Node* root) {
    if (!root) { 
        return;
    }
    postorder_rec(root->left);
    postorder_rec(root->right);
    cout << root->info << ' ';
}

// TC - O(n), SC - O(n)
void postorder(Node* root) {
    Node* cur = root;
    stack<Node*> sk;
    while (cur || !sk.empty()) {
        while (cur) {
            sk.push(cur);
            cur = cur->left;
        }
        cur = sk.top();
        cur = cur->right;
        sk.pop();
    }
}