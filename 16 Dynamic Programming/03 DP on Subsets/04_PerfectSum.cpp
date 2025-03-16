#include <bits/stdc++.h>
using namespace std;

int solution(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // in there type of problems we need to consider the case where the last index could either be zero then
    //  have to return 2;
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || (target == arr[0]))
            return 1;
        return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notPick = solution(ind - 1, target, arr, dp);
    int pick = 0;
    if (arr[ind] <= target)
        pick = solution(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = pick + notPick;
}

// int perfectSum(vector<int> &arr, int target)
// {
//     int n = arr.size();
//     vector<vector<int>> dp(n, vector<int> (target + 1, -1));
//     return solution(n-1, target, arr, dp);
// }
// tabulation code

int perfectSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    // convert the base cases
    dp[0][0] = 1;
    dp[0][arr[0]] = 1;
    if(arr[0] == 0)
    dp[0][0] = 2;

    for(int ind = 1 ; ind < n ; ind++)
    {
        for(int nt = 1 ; nt <= target ; nt++)
        {
            int notPick = dp[ind - 1][nt];
            int pick = 0;
            if(arr[ind] <= nt)
            pick = dp[ind -1][nt - arr[ind]];
            dp[ind][nt] = pick + notPick;
        }
    }
    return dp[n-1][target];
}

int main()
{

    return 0;
}