#include <bits/stdc++.h>
using namespace std;

int solution(int curr, int prev1, int prev2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    // out of bound case
    int n = grid.size();
    int m = grid[0].size();
    if (prev1 < 0 || prev1 >= m || prev2 < 0 || prev2 >= m)
    {
        return -1e8;
    }
    // base case
    if (curr == n - 1)
    {
        // check for the common cell
        if (prev1 == prev2)
        {
            return grid[curr][prev1];
        }
        else
        {
            return grid[curr][prev1] + grid[curr][prev2];
        }
    }
    if (dp[curr][prev1][prev2] != -1)
        return dp[curr][prev1][prev2];
    // looking for main case where we will try all of the 9 combos
    int maxi = -1e8;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int temp;
            if (prev1 == prev2)
            {
                temp = grid[curr][prev1] + solution(curr + 1, prev1 + i, prev2 + j, grid, dp);
            }
            else
            {
                temp = grid[curr][prev1] + grid[curr][prev2] + solution(curr + 1, prev1 + i, prev2 + j, grid, dp);
            }
            maxi = max(maxi, temp);
        }
    }
    return dp[curr][prev1][prev2] = maxi;
}

int solve(int n, int m, vector<vector<int>> &grid)
{
    // code here
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return solution(0, 0, m - 1, grid, dp);
}

int main()
{

    return 0;
}