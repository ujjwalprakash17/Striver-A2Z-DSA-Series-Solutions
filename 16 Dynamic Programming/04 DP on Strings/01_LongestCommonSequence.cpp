#include <bits/stdc++.h>
using namespace std;

// memoization solution
int solution(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp)
{
    // base case
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    // if match case
    if (text1[ind1] == text2[ind2])
    {
        return dp[ind1][ind2] = 1 + solution(ind1 - 1, ind2 - 1, text1, text2, dp);
    }
    // if not matching
    int reduceStr1 = solution(ind1 - 1, ind2, text1, text2, dp);
    int reduceStr2 = solution(ind1, ind2 - 1, text1, text2, dp);
    return dp[ind1][ind2] = max(reduceStr1, reduceStr2);
}

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solution(n - 1, m - 1, text1, text2, dp);
}

// tabulation solution
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // base case transformation
    // in these type of problems we do a transformation to acheive results
    // based on ind -1 so we do a shifting of index to + 1
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int j = 0; j <= n; j++)
        dp[j][0] = 0;

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (text1[ind1 - 1] == text2[ind2 - 1])
            {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            }
            else
            {
                int reduceStr1 = dp[ind1 - 1][ind2];
                int reduceStr2 = dp[ind1][ind2 - 1];
                dp[ind1][ind2] = max(reduceStr1, reduceStr2);
            }
        }
    }
    return dp[n][m];
}

int main()
{

    return 0;
}