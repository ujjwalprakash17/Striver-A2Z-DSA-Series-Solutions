#include <bits/stdc++.h>
using namespace std;
//recursion code
// int solution(int ind, vector<int> &nums)
// {
//     //base case -> if we are standing on 0th index what will happen
//     if(ind == 0) return nums[0];
//     //since we are moving 2 to lef wo we need to take care of this condition
//     if(ind < 0 ) return 0;
    
//     //pick adjacent element
//     int pick = nums[ind] + solution(ind - 2, nums);
//     // not pick 
//     int notPick = solution(ind - 1, nums);
//     return max(pick, notPick);
// }

//recursion + memoization
// int solution(int ind, vector<int> &nums, vector<int> &dp)
// {
//     if(ind == 0) return nums[0];
//     if(ind < 0) return 0;
    
//     // dp condition
//     if(dp[ind] != -1) return dp[ind];

//     int pick = nums[ind] + solution(ind - 2, nums, dp);
//     int notPick = solution(ind - 1,nums, dp);
//     return max(pick, notPick);
// }
//T.C - O(n) S.C- O(n) + O(n);

//tabulation call
int solution(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i = 1; i < n ; i++)
    {
        int take = nums[i];
        if(i > 1) take += prev2;
        int notTake = prev;
        int curri = max(take, notTake);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}


//space optimization
int rob(vector<int> &nums)
{
    int sum = 0;
    int ind = nums.size();
    // -> recursion call
    // return solution(ind - 1, nums);
    
    // -> memoization call
    //vector<int> dp(ind, -1);
    // return solution(ind - 1, nums, dp);

    // -> tabulation call


}
int main()
{
    vector<int> nums = {2,1,4,9};
    cout << rob(nums) << endl;
    return 0;
}