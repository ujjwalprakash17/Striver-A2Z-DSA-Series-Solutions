#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // step 1 : put in queue who are initially rotten
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                visited[i][j] = 2;
            }
        }
    }
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    int tm = 0;
    // Travese using BFS
    while (!q.empty())
    {
        // take out the front value so that you can traverse their neighbours
        int rVal = q.front().first.first;
        int cVal = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        // traverse their neighbour
        for (int i = 0; i < 4; i++)
        {
            int nRowVal = rVal + delRow[i];
            int nColVal = cVal + delCol[i];
            // check for validity of the neighbouring elements
            if (nRowVal >= 0 && nRowVal < n && nColVal >= 0 && nColVal < m && visited[nRowVal][nColVal] == 0 && grid[nRowVal][nColVal] == 1)
            {
                q.push({{nRowVal, nColVal}, t + 1});
                visited[nRowVal][nColVal] = 2;
            }
        }
    }
    // check whether any of the fresh oranges remaining
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && visited[i][j] != 2)
                return -1;
        }
    }
    return tm;
}

int main()
{

    return 0;
}