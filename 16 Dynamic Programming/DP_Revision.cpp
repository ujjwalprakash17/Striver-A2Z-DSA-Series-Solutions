#include <bits/stdc++.h>
using namespace std;

bool solution(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == -1 )
    {
        return target == 0;
    }
    if(dp[ind][target] != -1) return dp[ind][target];
    bool notPick = solution(ind - 1, target, arr, dp);
    bool pick = false;
    if (target >= arr[ind])
        pick = solution(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = pick || notPick;
}

bool isSubsetSum(vector<int> &arr, int sum)
{
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
    return solution(n-1, sum, arr, dp);
}

bool isSubsetSum(vector<int> &arr, int sum)
{
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int> (sum + 1, 0));

    for(int i = 0; i <= n ; i++){
        dp[i][0] = 1;
    }

    for(int ind = 1; ind <= n ; ind++){
        for(int target = 0; target <= sum ; target++){
            bool notPick = dp[ind-1][target];
            bool pick = false;
            if(target >= arr[ind]){
                pick = dp[ind-1][target-arr[ind]]
            }
            dp[ind][target] = pick || notPick;
        }
    }
    return dp[n][sum];
}

bool solution(int target, vector<int> &nums){

    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    for(int i = 0; i <= n ; i++)
    {
        dp[i][0] = 1;
    }

    for(int ind = 1; ind <= n ; ind++)
    {
        for(int sum = 1 ; sum <= target ; sum++)
        {
            int notPick = dp[ind-1][sum];
            int pick = 0;
            if(nums[ind] <= sum)
            pick = dp[ind-1][sum-nums[ind]];
            dp[ind][sum] = pick | notPick;
        }
    }
    return dp[n][target];

}

bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = 0;
    for(int val : nums){
        totalSum += val;
    }
    if(totalSum % 2 != 0 )return false;
    int newTarget = totalSum / 2;
    return solution (newTarget, nums);
}

int main()
{

    return 0;
}
