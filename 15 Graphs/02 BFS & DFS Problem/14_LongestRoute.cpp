#include <bits/stdc++.h>
using namespace std;


// Shortest Path → BFS
// Longest Path → DFS (with backtracking to unmark visited nodes)

void dfsTraversal(int stRow, int stCol, int dx, int dy, int currLength, int &ans, vector<vector<int>> &mat, vector<vector<int>> &visited)
{
    int n = mat.size();
    int m = mat[0].size();
    visited[stRow][stCol] = 1;
    if (stRow == dx && stCol == dy)
    {
        ans = max(ans, currLength);
    }
    // doing something something
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nRow = stRow + delRow[i];
        int nCol = stCol + delCol[i];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && mat[nRow][nCol] == 1 && !visited[nRow][nCol])
        {
            dfsTraversal(nRow, nCol, dx, dy, currLength + 1, ans, mat, visited);
        }
    }
    visited[stRow][stCol] = 0;
}

int longestPath(int n, int m, vector<vector<int>> &mat, int sx, int sy, int dx, int dy)
{
    // Write your code here
    if (mat[sx][sy] == 0)
        return -1;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int ans = 0;
    dfsTraversal(sx, sy, dx, dy, 0, ans, mat, visited);
    return ans;
}

int main() {
    
    return 0;
}