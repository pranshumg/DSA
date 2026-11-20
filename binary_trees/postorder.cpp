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
    stack<Node*> sk1, sk2;
    while (cur || !sk1.empty()) {
        while (cur) {
            sk2.push(cur);
            sk1.push(cur);
            cur = cur->right;
        }
        cur = sk1.top();
        sk1.pop();
        cur = cur->left;
    }
    while (!sk2.empty()) {
        cout << sk2.top()->info << ' ';
        sk2.pop();
    }
}

// TC - O(n), SC - O(h)
void postorder(Node* root) {
    Node* cur = root;
    Node* prev = nullptr;
    stack<Node*> sk;
    while (cur || !sk.empty()) {
        while (cur) {
            sk.push(cur);
            cur = cur->left;
        }
        cur = sk.top();
        if (!cur->right || cur->right == prev) {
            cout << cur->info << ' ';
            sk.pop();
            prev = cur;
            cur = nullptr;
        } else {
            cur = cur->right;
        }
    }
}