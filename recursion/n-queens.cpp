#include <bits/stdc++.h>

using namespace std;

/* N-queens */
// https://leetcode.com/problems/n-queens/

bool check(int n, int row, int col, vector<string>& board) {
  for (int i = 0; i <= col; i++) {
    if (board[row][i] == 'Q') {
      return false;
    }
  }
  int dup_row = row, dup_col = col;
  while (row >= 0 && col >= 0) {
    if (board[row][col] == 'Q') {
      return false;
    }
    row--;
    col--;
  }
  row = dup_row, col = dup_col;
  while (row < n && col >= 0) {
    if (board[row][col] == 'Q') {
      return false;
    }
    row++;
    col--;
  }
  return true;
}

void solve(int col, int n, vector<string>& board, vector<vector<string>>& res) {
  if (col == n) {
    res.push_back(board);
    return;
  }
  for (int row = 0; row < n; row++) {
    if (check(n, row, col, board)) {
      board[row][col] = 'Q';
      solve(col + 1, n, board, res);
      board[row][col] = '.';
    }
  }
}

// TC - O(n! * n), SC - O(n * n)
vector<vector<string>> n_queens(int n) {
  vector<vector<string>> res;
  vector<string> board(n);
  string s(n, '.');
  for (auto& a : board) {
    a = s;
  }
  solve(0, n, board, res);
  return res;
}

void solve(int col, int n, vector<bool>& lower_diagnol, vector<bool>& upper_diagnol, vector<bool>& left_row, vector<string>& board, vector<vector<string>>& res) {
  if (col == n) {
    res.push_back(board);
    return;
  }
  for (int row = 0; row < n; row++) {
    if (!left_row[row] && !lower_diagnol[row + col] && !upper_diagnol[n - 1 + col - row]) {
      board[row][col] = 'Q';
      left_row[row] = true;
      lower_diagnol[row + col] = true;
      upper_diagnol[n - 1 + col - row] = true;
      solve(col + 1, n, lower_diagnol, upper_diagnol, left_row, board, res);
      board[row][col] = '.';
      left_row[row] = false;
      lower_diagnol[row + col] = false;
      upper_diagnol[n - 1 + col - row] = false;
    }
  }
}

// TC - O(n!), SC - O(n * n)
vector<vector<string>> n_queens(int n) {
  vector<vector<string>> res;
  vector<string> board(n);
  string s(n, '.');
  for (auto& a : board) {
    a = s;
  }
  vector<bool> lower_diagnol(2 * n - 1, false), upper_diagnol(2 * n - 1, false), left_row(n, false);
  solve(0, n, lower_diagnol, upper_diagnol, left_row, board, res);
  return res;
}