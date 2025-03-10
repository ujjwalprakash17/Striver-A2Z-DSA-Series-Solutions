// 931. Minimum Falling Path Sum
#include <bits/stdc++.h>
using namespace std;

int solution(int currLvl, int prev, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (prev < 0 || prev >= matrix[0].size())
        return INT_MAX;
    if (currLvl == 0)
        return matrix[currLvl][prev];

    if (dp[currLvl][prev] != -1)
        return dp[currLvl][prev];
    int u = matrix[currLvl][prev] + solution(currLvl - 1, prev, matrix, dp);
    int ld = matrix[currLvl][prev] + solution(currLvl - 1, prev - 1, matrix, dp);
    int rd = matrix[currLvl][prev] + solution(currLvl - 1, prev + 1, matrix, dp);

    return dp[currLvl][prev] = min(u, min(ld, rd));
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // handling base case --> think of it like what are you doing in memoization when you are reaching to level 0
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }
    // handle loops
    // think of it like how many changing parameter are there in memoization
    // we can clearly see that we have 2 changing parameters 1. currLvl 2. prev

    // where do we start from since we already have handled the case for 0 th level so we need to start from 1st
    for (int i = 1; i < n; i++)
    {
        // now by looking at a particular level find out what are you doing?
        // we are looking for left diagonal, up , right diagonal

        // recursive me hamare pass previous diya hua tha
        // lekin yaha hm previous ki saari possibilities ko consider krte hue chalenge
        for (int j = 0; j < m; j++)
        {
            int u = matrix[i][j] + dp[i - 1][j];
            int ld = matrix[i][j];
            if (j - 1 >= 0)
                ld += dp[i - 1][j - 1];
            else
                ld += INT_MAX;
            int rd = matrix[i][j];
            if (j + 1 < m)
                rd += dp[i - 1][j + 1];
            else
                rd += INT_MAX;
            dp[i][j] = min(u, min(ld, rd));
        }
    }


    // now to return the answer we need to look up in dp, that which value is highest
    // so to do so we will lookup the last level in dp 
    int ans = INT_MAX;
    for(int i = 0; i < m ; i++)
    {
        ans = min(ans, dp[n-1][i]);
    }
    return ans;
}

int main()
{

    return 0;
}