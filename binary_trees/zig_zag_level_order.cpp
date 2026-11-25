#include <bits/stdc++.h>

using namespace std;

/* zig zag level order traversal */
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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

// TC - O(n), SC - O(n)
vector<vector<int>> zig_zag_level_order(Node* root) {
    if (!root) {
        return {};
    }
    vector<vector<int>> res;
    queue<Node*> qe;
    qe.push(root);
    int level = 0;
    while (!qe.empty()) {
        int sz = int(qe.size());
        vector<int> tmp(sz);
        for (int i = 0; i < sz; i++) {
            auto tp = qe.front();
            qe.pop();
            if (tp->left) {
                qe.push(tp->left);
            }
            if (tp->right) {
                qe.push(tp->right);
            }
            tmp[level & 1 ? sz - i - 1 : i] = tp->info;
        }
        res.push_back(tmp);
        level++;
    }
    return res;
}