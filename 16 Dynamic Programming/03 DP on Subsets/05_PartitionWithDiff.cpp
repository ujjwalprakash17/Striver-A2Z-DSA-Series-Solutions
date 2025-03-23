#include <bits/stdc++.h>
using namespace std;


int solution(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind < 0)
        return target == 0;
    if(dp[ind][target] != -1) return dp[ind][target];
    int notPick = solution(ind - 1, target, arr, dp);
    int pick = 0;
    if (arr[ind] <= target)
        pick = solution(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target]= pick + notPick;
}

int countPartitions(vector<int> &arr, int d)
{
    // Code here
    int totalSum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    if ((totalSum + d) % 2 != 0 || totalSum < d) 
    return 0;
    int target = (totalSum + d) / 2;
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    return solution(n- 1, target, arr, dp);
}


int countPartitions(vector<int> &arr, int d)
{
    // Code here
    int totalSum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    if ((totalSum + d) % 2 != 0 || totalSum < d) 
    return 0;
    int target = (totalSum + d) / 2;
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    dp[0][0] = 1;
    for(int ind = 1 ; ind <= n  ; ind++)
    {
        for(int t = 0; t <= target ; t++)
        {
            int notPick = dp[ind-1][t];
            int pick = 0;
            if(arr[ind-1] <= t)
            pick = dp[ind-1][t-arr[ind-1]];
            dp[ind][t] = pick + notPick;
        }
    }
    return dp[n][target];
}

int main()
{

    return 0;
}