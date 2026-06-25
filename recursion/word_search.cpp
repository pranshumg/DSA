#include <bits/stdc++.h>

using namespace std;

/* Word search */
// https://leetcode.com/problems/word-search/

bool solve(int idx, int i, int j, int m, int n, string& word, vector<vector<bool>>& vis, vector<vector<char>>& board) {
    if (idx == int(word.size())) {
        return true;
    }
    if (i + 1 < m && !vis[i + 1][j] && board[i + 1][j] == word[idx]) {
        vis[i + 1][j] = true;
        if (solve(idx + 1, i + 1, j, m, n, word, vis, board)) return true;
        vis[i + 1][j] = false;
    }
    if (i - 1 >= 0 && !vis[i - 1][j] && board[i - 1][j] == word[idx]) {
        vis[i - 1][j] = true;
        if (solve(idx + 1, i - 1, j, m, n, word, vis, board)) return true;
        vis[i - 1][j] = false;
    }
    if (j + 1 < n && !vis[i][j + 1] && board[i][j + 1] == word[idx]) {
        vis[i][j + 1] = true;
        if (solve(idx + 1, i, j + 1, m, n, word, vis, board)) return true;
        vis[i][j + 1] = false;
    }
    if (j - 1 >= 0 && !vis[i][j - 1] && board[i][j - 1] == word[idx]) {
        vis[i][j - 1] = true;
        if (solve(idx + 1, i, j - 1, m, n, word, vis, board)) return true;
        vis[i][j - 1] = false;
    }
    return false;
}

// TC - O(m * n * 3^L), SC - O(m * n + L) where L = word length
bool exist(vector<vector<char>>& board, string word) {
    int m = int(board.size()), n = int(board[0].size());
    string s = "";
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0]) {
                vis[i][j] = true;
                if (solve(1, i, j, m, n, word, vis, board)) {
                    return true;
                }
                vis[i][j] = false;
            }
        }
    }
    return false;
}