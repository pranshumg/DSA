#include <bits/stdc++.h>

using namespace std;
    
/* Sudoku */
// https://leetcode.com/problems/sudoku-solver/

bool is_valid(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) return false;
        if (board[i][col] == c) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
    }  
    return true;
}

bool solve(vector<vector<char>>& board) {
    for (int i = 0; i < int(board.size()); i++) {
        for (int j = 0; j < int(board.size()); j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (is_valid(board, i, j, c)) {
                        board[i][j] = c;
                        if (solve(board)) {
                            return true;
                        } else {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// TC - O(9^m), SC - O(m) where m is the number of empty cells
void sudoku(vector<vector<char>>& board) {
    solve(board);
}