#include <bits/stdc++.h>
using namespace std;

int solution(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int notPick = solution(ind - 1, target, arr, dp);
    int pick = 0;
    if (arr[ind] <= target)
    {
        pick = solution(ind - 1, target - arr[ind], arr, dp);
    }
    return dp[ind][target] = pick + notPick;
}
// tabulation version
int countPartitions(vector<int> &arr, int d)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((d + sum) % 2 != 0)
        return 0;
    int target = (d + sum) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // transforming base cases in tabulation
    dp[0][0] = 1;
    if (arr[0] <= target)
        dp[0][arr[0]] = 1;
    if (arr[0] == 0)
        dp[0][0] = 2;
    for(int ind = 1 ; ind < n ; ind++)
    {
        for(int newTarget = 0; newTarget <= target ; newTarget++)
        {
            int notPick = dp[ind -1][newTarget];
            int pick = 0;
            if(arr[ind] <= newTarget)
            {
                pick = dp[ind-1][newTarget - arr[ind]];
            }
            dp[ind][newTarget] = pick + notPick;
        }
    }
    return dp[n-1][target];
}

int countPartitions(vector<int> &arr, int d)
{
    // Code here
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((d + sum) % 2 != 0)
        return 0;
    int target = (d + sum) / 2;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return solution(n - 1, target, arr, dp);
}

int main()
{

    return 0;
}