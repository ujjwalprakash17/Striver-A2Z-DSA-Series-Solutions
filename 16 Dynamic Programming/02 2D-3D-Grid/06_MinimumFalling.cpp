// 931. Minimum Falling Path Sum
#include <bits/stdc++.h>
using namespace std;

int solution(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    // base case
    if (col < 0 || col >= matrix.size())
        return INT_MAX;
    if (row == 0)
        return matrix[0][col];
    if (dp[row][col] != -1)
        return dp[row][col];
    int ld = solution(row - 1, col - 1, matrix, dp);
    int up = solution(row - 1, col, matrix, dp);
    int rd = solution(row - 1, col + 1, matrix, dp);
    return dp[row][col] = matrix[row][col] + min(up, min(ld, rd));
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int ans = INT_MAX;
    vector<vector<int>> dp(n , vector<int> (n , -1));
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, solution(n - 1, i, matrix, dp));
    }
    return ans;
}

int main()
{

    return 0;
}