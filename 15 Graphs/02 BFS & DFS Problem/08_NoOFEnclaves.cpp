#include <bits/stdc++.h>
using namespace std;

// Approach : we need to find all the ones who are connected to the boundary in dfs wise
// count all the remaining 1s who are not connected to the boundary

void dfsTraversal(int stRow, int stCol, vector<vector<int>> &grid, vector<vector<int>> &visited)
{
    visited[stRow][stCol] = 1;
    int n = grid.size();
    int m = grid[0].size();
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nRow = stRow + delRow[i];
        int nCol = stCol + delCol[i];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && !visited[nRow][nCol])
        {
            dfsTraversal(nRow, nCol, grid, visited);
        }
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1)
        {
            dfsTraversal(i, 0, grid, visited);
        }
        if (grid[i][m - 1] == 1)
        {
            dfsTraversal(i, m - 1, grid, visited);
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 1)
        {
            dfsTraversal(0, j, grid, visited);
        }
        if (grid[n - 1][j] == 1)
        {
            dfsTraversal(n - 1, j, grid, visited);
        }
    }
    int cnt = 0;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m ; j++){
            if(grid[i][j] == 1 && !visited[i][j])
            cnt++;
        }
    }
    return cnt;
}

int main()
{

    return 0;
}