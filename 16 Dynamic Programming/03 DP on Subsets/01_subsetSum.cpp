#include <bits/stdc++.h>
using namespace std;

bool solution(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    // out of bound
    if (target == 0)
        return true;
    if (ind == 0)
    {
        return (arr[0] == target);
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool notTake = solution(ind - 1, target, arr, dp);
    bool take = false;
    if (arr[ind] <= target)
        take = solution(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = take || notTake;
}
// ask good question to your self 
bool isSubsetSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for(int ind = 0; ind < n ; ind++)
    {
        dp[ind][0] = true;
    }
    //we can only check for the zeroth value of arr if and only if the value of zero th index is less than or equal to target
    if(arr[0] <= target )
    dp[0][arr[0]] = true;
    for(int ind = 1 ; ind  < n ; ind++)
    {
        for(int k = 0; k <= target ; k++)
        {
            bool notTake = dp[ind - 1][k];
            bool take = false;
            if(arr[ind] <= k)
            {
                take = dp[ind-1][k-arr[ind]];
            }
            dp[ind][k] = take || notTake;
        }
    }
    return dp[n-1][target];
}

int main()
{

    return 0;
}