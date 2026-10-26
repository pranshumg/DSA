#include <bits/stdc++.h>

using namespace std;

/* Rat in a maze */

void solve(int row, int col, int n, string& s, vector<vector<bool>>& vis, vector<vector<int>>& maze, vector<string>& res) {
    if (row == n - 1 && col == n - 1) {
        res.push_back(s);
        return;
    }
    if (row + 1 < n && !vis[row + 1][col] && maze[row + 1][col] == 1) {
        s.push_back('D');
        vis[row + 1][col] = true;
        solve(row + 1, col, n, s, vis, maze, res);
        s.pop_back();
        vis[row + 1][col] = false;
    }
    if (row - 1 >= 0 && !vis[row - 1][col] && maze[row - 1][col] == 1) {
        s.push_back('U');
        vis[row - 1][col] = true;
        solve(row - 1, col, n, s, vis, maze, res);
        s.pop_back();
        vis[row - 1][col] = false;
    }
    if (col + 1 < n && !vis[row][col + 1] && maze[row][col + 1] == 1) {
        s.push_back('R');
        vis[row][col + 1] = true;
        solve(row, col + 1, n, s, vis, maze, res);
        s.pop_back();
        vis[row][col + 1] = false;
    }
    if (col - 1 >= 0 && !vis[row][col - 1] && maze[row][col - 1] == 1) {
        s.push_back('L');
        vis[row][col - 1] = true;
        solve(row, col - 1, n, s, vis, maze, res);
        s.pop_back();
        vis[row][col - 1] = false;
    }
}

// TC - O(4^(n * n)), SC - O(n * n)
vector<string> rat_in_a_maze(vector<vector<int>>& maze, int n) {
    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
        return {};
    }
    vector<string> res;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vis[0][0] = true;
    string s = "";
    solve(0, 0, n, s, vis, maze, res);
    return res;
}