#include <bits/stdc++.h>
using namespace std;

// Approach :
// 1. we just need to visit the boundary 0s and their connected 0s in DFS traversal
// as soon as we visited all of them it will be obvious that the remaining 0s are going to be captured

void dfsTraversal(int stRow, int stCol, vector<vector<char>> &board, vector<vector<int>> &visited)
{
    visited[stRow][stCol] = 1;
    int n = board.size();
    int m = board[0].size();
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nRow = stRow + delRow[i];
        int nCol = stCol + delCol[i];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && board[nRow][nCol] == 'O' && !visited[nRow][nCol])
        {
            dfsTraversal(nRow, nCol, board, visited);
        }
    }
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    // visit all the edges of the board, and traverse them dfs wise
    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O')
        {
            dfsTraversal(i, 0, board, visited);
        }
        if (board[i][m - 1] == 'O')
        {
            dfsTraversal(i, m - 1, board, visited);
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (board[0][j] == 'O')
        {
            dfsTraversal(0, j, board, visited);
        }
        if (board[n - 1][j] == 'O')
        {
            dfsTraversal(n - 1, j, board, visited);
        }
    }

    // now at last make every 0 -> x which is surrounded by x

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '0' && !visited[i][j])
            {
                board[i][j] = 'X';
            }
        }
    }
}
int main()
{
    vector<std::vector<char>> matrix = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}};
    solve(matrix);
    return 0;
}