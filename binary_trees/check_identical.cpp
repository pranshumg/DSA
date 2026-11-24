#include <bits/stdc++.h>

using namespace std;

/* check if two trees are identical */
// https://leetcode.com/problems/same-tree/

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

void rec(Node* p, Node* q, bool& b) {
    if (!b) {
        return;
    }
    if (!p && !q) {
        return;
    }
    if ((!p && q) || (p && !q) || p->info != q->info) {
        b = false;
        return;
    }
    rec(p->left, q->left, b);
    rec(p->right, q->right, b);
}

// TC - O(n), SC - O(h)
bool is_same(Node* p, Node* q) {
    bool b = true;
    rec(p, q, b);
    return b;
}
