#include <bits/stdc++.h>
using namespace std;

// using bfs
void bfsTraversal(int stRow, int stCol, int **arr, vector<vector<int>> &visited)
{
    queue<pair<int, int>> q;
    q.push({stRow, stCol});
    visited[stRow][stCol] = 1;
    int n = visited.size();
    int m = visited[0].size();
    int delRow[] = {-1, 0, 1, 0, -1, -1, +1, +1};
    int delCol[] = {0, +1, 0, -1, -1, +1, +1, -1};
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        // traverse in 8 directions
        for (int i = 0; i < 8; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && arr[nRow][nCol] == 1)
            {
                q.push({nRow, nCol});
                visited[nRow][nCol] = 1;
            }
        }
    }
}

int getTotalIslands(int **arr, int n, int m)
{
    // Write your code here.
    int cnt = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // check here that if its not visited then
            if (arr[i][j] == 1 && !visited[i][j])
            {
                // call here bfsTraversal
                bfsTraversal(i, j, arr, visited);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{

    int rows = 4, cols = 5;

    // Create a double pointer
    int **arr = new int *[rows];

    // Allocate memory for each row
    for (int i = 0; i < rows; ++i)
    {
        arr[i] = new int[cols];
    }

    // Initialize the matrix
    int values[4][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1}};

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            arr[i][j] = values[i][j];
        }
    }
    cout << getTotalIslands(arr, rows, cols);

    return 0;
}