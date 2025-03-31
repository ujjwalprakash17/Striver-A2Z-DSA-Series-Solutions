// #include <bits/stdc++.h>
// using namespace std;

// int solution(int ind, int target, vector<int> &nums, int val, vector<vector<int>> &dp)
// {
//     // base case
//     if (ind == 0)
//     {
//         if (target == 0 && nums[0] == 0)
//             return 2;
//         else if (target - nums[0] == 0)
//             return 1;
//         else if (target + nums[0] == 0)
//             return 1;
//         else
//             return 0;
//     }
//     if (dp[ind][target + val] != -1)
//         return dp[ind][target + val];
//     // main cases
//     int takePos = solution(ind - 1, target + nums[ind], nums, val, dp);
//     int takeNeg = solution(ind - 1, target - nums[ind], nums, val, dp);
//     return dp[ind][target + val] = takePos + takeNeg;
// }

// int findTargetSumWays(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     int offSet = 0;
//     for (int i : nums)
//     {
//         offSet += i;
//     }
//     if (abs(target) > offSet)
//         return 0;
//     vector<vector<int>> dp(n, vector<int>((2 * offSet) + 1, -1));
//     return solution(n - 1, target, nums, offSet, dp);
// }

//remove unnecessary dp calls to reduce the overhead of offSet

// int solution(int ind, int target, vector<int> &nums,
//              unordered_map<string, int> &dp)
// {
//     string key = to_string(ind) + "," + to_string(target);
//     // base case
//     if (ind == 0)
//     {
//         if (target == 0 && nums[0] == 0)
//             return 2;
//         else if (target - nums[0] == 0)
//             return 1;
//         else if (target + nums[0] == 0)
//             return 1;
//         else
//             return 0;
//     }
//     if (dp.find(key) != dp.end())
//         return dp[key];
//     // main cases
//     int takePos = solution(ind - 1, target + nums[ind], nums, dp);
//     int takeNeg = solution(ind - 1, target - nums[ind], nums, dp);
//     return dp[key] = takePos + takeNeg;
// }

// int findTargetSumWays(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     unordered_map<string, int> dp;
//     return solution(n - 1, target, nums, dp);
// }

// int main()
// {

//     return 0;
// }


// int findTargetSumWays(vector<int> &nums, int target) {
//     int n = nums.size();
//     unordered_map<string, int> dp;

//     // Offset to handle negative target values
//     int sum = 0;
//     for (int num : nums) {
//         sum += num;
//     }
//     int offset = sum;

//     // Initialize base case for dp
//     for (int t = -sum; t <= sum; t++) {
//         string key = "0," + to_string(t);
//         if (t == 0 && nums[0] == 0)
//             dp[key] = 2;
//         else if (t == nums[0] || t == -nums[0])
//             dp[key] = 1;
//         else
//             dp[key] = 0;
//     }

//     // Fill dp table
//     for (int ind = 1; ind < n; ind++) {
//         unordered_map<string, int> newDp; // Use a temporary map for the next state
//         for (int t = -sum; t <= sum; t++) {
//             string key = to_string(ind) + "," + to_string(t);
//             string posKey = to_string(ind - 1) + "," + to_string(t - nums[ind]);
//             string negKey = to_string(ind - 1) + "," + to_string(t + nums[ind]);

//             int takePos = (dp.find(posKey) != dp.end()) ? dp[posKey] : 0;
//             int takeNeg = (dp.find(negKey) != dp.end()) ? dp[negKey] : 0;

//             newDp[key] = takePos + takeNeg;
//         }
//         dp = newDp; // Update dp with the new state
//     }

//     // Return the result
//     string key = to_string(n - 1) + "," + to_string(target);
//     return (dp.find(key) != dp.end()) ? dp[key] : 0;
// }



#include <bits/stdc++.h>
using namespace std;



int main() {
    
    return 0;
}