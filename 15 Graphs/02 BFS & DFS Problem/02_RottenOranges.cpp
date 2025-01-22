#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        // Added all the rotten oranges first
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
            }
        }
        int tm = 0;
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            q.pop();
            tm = max(tm, time);
            for (int i = 0; i < 4; i++) {
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];
                if (nRow >= 0 && nRow < row && nCol >= 0 && nCol < col &&
                    visited[nRow][nCol] != 2 && grid[nRow][nCol] == 1) {
                    q.push({{nRow, nCol}, time + 1});
                    visited[nRow][nCol] = 2;
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (visited[i][j] != 2 && grid[i][j] == 1)
                    return -1;
            }
        }
        return tm;
    }
};


int main()
{
    
    return 0;
}