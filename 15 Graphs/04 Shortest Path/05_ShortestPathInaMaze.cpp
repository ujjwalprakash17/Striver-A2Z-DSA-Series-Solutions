#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
    return -1;
    set<pair<int, pair<int, int>>> distSet;
    vector<vector<int>> distMatrix(n, vector<int>(n, 1e9));
    distMatrix[0][0] = 1;
    distSet.insert({1, {0, 0}});
    while (!distSet.empty())
    {
        auto currLocation = distSet.begin();
        int currDist = currLocation->first;
        int currRow = currLocation->second.first;
        int currCol = currLocation->second.second;
        distSet.erase(currLocation);
        if (currRow == n - 1 && currCol == n - 1) {
            return currDist;
        }
        
        // Skip if we've already found a better path to this cell
        if (currDist > distMatrix[currRow][currCol]) {
            continue;
        }
        int delRow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int delCol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        for (int i = 0; i < 8; i++)
        {
            int nRow = currRow + delRow[i];
            int nCol = currCol + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] == 0 && currDist + 1 < distMatrix[nRow][nCol]){
                distSet.erase({distMatrix[nRow][nCol] , {nRow, nCol}});
                distSet.insert({currDist + 1, {nRow, nCol}});
                distMatrix[nRow][nCol] = currDist + 1;
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}