#include <bits/stdc++.h>
using namespace std;

bool solution(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return (nums[0] == target);
    if(dp[ind][target] != -1) return dp[ind][target];
    bool notTake = solution(ind - 1 , target, nums, dp);
    bool take = false;
    if(nums[ind] <= target)
    take = solution(ind -1 , target - nums[ind], nums, dp);
    return dp[ind][target] = take || notTake;
}

bool canPartition(vector<int> &nums)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    if(totalSum % 2 != 0) return false;
    int newtarget = totalSum / 2;
    vector<vector<bool>> dp(n, vector<bool> (newtarget + 1, false));
    // return solution(n-1, totalSum /2 , nums, dp);
    for(int i = 0; i < n ; i++)
    {
        dp[i][0] = true;
    }
    if(nums[0] <= newtarget)
    dp[0][nums[0]] = true;

    for(int ind = 1 ; ind < n ; ind++)
    {
        for(int target = 1 ; target <= newtarget ; target++)
        {
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(nums[ind] <= target)
            {
                take = dp[ind -1][target - nums[ind]];
            }
            dp[ind][target] = take || notTake;
        }
    }
    return dp[n-1][newtarget];

}

int main()
{

    return 0;
}