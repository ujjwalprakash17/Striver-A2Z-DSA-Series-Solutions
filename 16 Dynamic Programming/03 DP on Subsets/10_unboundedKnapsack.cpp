#include <bits/stdc++.h>
using namespace std;

int solution(int ind, int capacity, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (ind < 0)
    {
        return 0;
    }
    if (dp[ind][capacity] != -1)
        return dp[ind][capacity];
    int notPick = solution(ind - 1, capacity, val, wt, dp);
    int pick = 0;
    if (wt[ind] <= capacity)
    {
        pick = val[ind] + solution(ind, capacity - wt[ind], val, wt, dp);
    }
    return dp[ind][capacity] = max(pick, notPick);
}

int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    // code here
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    return solution(n - 1, capacity, val, wt, dp);
}
//tabulation
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    // code here
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for(int ind = 1; ind <= n ; ind++)
    {
        for(int cpcity = 0; cpcity <= capacity; cpcity++)
        {
            int notPick = dp[ind-1][cpcity];
            int pick = 0;
            if(wt[ind-1] <= cpcity){
                pick= val[ind-1] + dp[ind][cpcity-wt[ind-1]];
            }
            dp[ind][cpcity] = max(pick , notPick);
        }
    }

    return dp[n][capacity];
}

int main()
{

    return 0;
}