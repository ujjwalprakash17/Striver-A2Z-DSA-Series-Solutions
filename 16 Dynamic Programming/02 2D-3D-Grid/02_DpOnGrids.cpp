#include <bits/stdc++.h>
using namespace std;
//recursion + memoization
int solution(int m, int n, vector<vector<int>> &dp)
{
  if (m == 1 && n == 1)
    return 1;
  if (dp[m][n] != -1)
    return dp[m][n];
  long long right = 0, down = 0;
  if (n > 1)
    right = solution(m, n - 1, dp);
  if (m > 1)
    down = solution(m - 1, n, dp);
  return dp[m][n] = right + down;
}
int uniquePaths(int m, int n)
{
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
  return solution(m, n, dp);
}

int main()
{

  return 0;
}
