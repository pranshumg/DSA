#include <bits/stdc++.h>

using namespace std;

/* level order traversal of binary tree */
// https://leetcode.com/problems/binary-tree-level-order-traversal/

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

// TC - O(n), SC - O(n)
vector<vector<int>> level_order(Node* root) {
    if (!root) {
        return {};
    }
    vector<vector<int>> res;
    queue<Node*> qe;
    qe.push(root);
    while (!qe.empty()) {
        int sz = int(qe.size());
        vector<int> tmp;
        for (int i = 0; i < sz; i++) {
            auto tp = qe.front();
            qe.pop();
            if (tp->left) {
                qe.push(tp->left);
            }
            if (tp->right) {
                qe.push(tp->right);
            }
            tmp.push_back(tp->info);
        }
        res.push_back(tmp);
    }
    return res;
}