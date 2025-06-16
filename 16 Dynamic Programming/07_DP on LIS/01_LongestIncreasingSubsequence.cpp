#include <bits/stdc++.h>
using namespace std;

// int solution(int ind, int prev, vector<int> &nums, vector<vector<int>>&dp)
// {
//     if(ind >= nums.size() ) return 0;
//     if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
//     int notPick = solution(ind + 1, prev, nums, dp);
//     int pick = 0;
//     if(prev == -1 || nums[prev] < nums[ind]){
//         pick = 1 + solution(ind + 1, ind, nums, dp);
//     }
//     return dp[ind][prev+1] = max(pick, notPick);
// }

// int lengthOfLIS(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<vector<int>>dp(n, vector<int>(n+1, -1));
//     return solution(0, -1, nums, dp);
// }

int solution(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (ind >= n)
        return 0;
    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];
    int notPick = solution(ind + 1, prev, nums, dp);
    int pick = 0;
    if (prev == -1 || nums[prev] < nums[ind])
    {
        pick = 1 + solution(ind + 1, ind, nums, dp);
    }
    return dp[ind][prev + 1] = max(pick, notPick);
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solution(0, -1, nums, dp);
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prev = ind - 1; prev >= -1; prev--) {
            int notPick = dp[ind + 1][prev + 1];  
            int pick = 0;
            if (prev == -1 || nums[ind] > nums[prev]) {  
                pick = 1 + dp[ind + 1][ind + 1];  
            }
            dp[ind][prev + 1] = max(pick, notPick); 
        }
    }
    
    return dp[0][0];
}

int main()
{

    return 0;
}




// # Longest Increasing Subsequence (LIS) - Step by Step DP Table

// ## Small Example: `[3, 1, 5, 4]`

// Let's solve this problem step by step with a small array. Our goal is to find the longest increasing subsequence.

// ## Step 0: Understanding the Problem and Setting Up

// For this array `[3, 1, 5, 4]`:
// - Possible increasing subsequences: `[3, 5]`, `[3, 4]`, `[1, 5]`, `[1, 4]`, `[3]`, `[1]`, `[5]`, `[4]`
// - The longest ones are `[3, 5]`, `[3, 4]`, `[1, 5]`, `[1, 4]` with length 2

// ### DP State Definition
// - `dp[ind][prev+1]` = Length of LIS starting from index `ind` with previous element at index `prev`
// - We use `prev+1` to handle case when prev = -1 (no previous element)

// ### DP Array Initialization
// - We'll create a DP array of size `(n+1) × (n+1)`, initialized with 0
// - In our case: 5×5 array (0 to 4)

// ## Base Cases
// The base case represents when we reach past the end of array (ind = n):
// - `dp[4][...]` = 0 (When we're past the array end, LIS length is 0)

// ## Step 1: Working Backwards from Last Element (Bottom-Up Approach)

// We start filling our DP table from the last index (3) and move backwards to index 0.

// ### Filling in dp[3][...] (Element = 4, Index = 3)

// For `ind = 3` (element = 4):
// - For `prev = 2` (5):
//   - Can we pick 4 after 5? No, because 4 < 5
//   - So `dp[3][3] = 0` (not picked)
// - For `prev = 1` (1):
//   - Can we pick 4 after 1? Yes, because 4 > 1
//   - So `dp[3][2] = 1` (picked)
// - For `prev = 0` (3):
//   - Can we pick 4 after 3? Yes, because 4 > 3
//   - So `dp[3][1] = 1` (picked)
// - For `prev = -1` (no previous element):
//   - We can always pick with no previous constraint
//   - So `dp[3][0] = 1` (picked)

// ### DP Table after processing index 3:
// ```
//     prev  -1   0    1    2    3
// ind
//  0     ?    ?    ?    ?    ?
//  1     ?    ?    ?    ?    ?
//  2     ?    ?    ?    ?    ?
//  3     1    1    1    0    X
//  4     0    0    0    0    0
// ```

// ## Step 2: Process Index 2 (Element = 5)

// For `ind = 2` (element = 5):
// - For `prev = 1` (1):
//   - Can we pick 5 after 1? Yes, because 5 > 1
//   - If picked: 1 + dp[3][2+1] = 1 + dp[3][3] = 1 + 0 = 1
//   - If not picked: dp[3][1+1] = dp[3][2] = 1
//   - Maximum = 1
//   - So `dp[2][2] = 1`
// - For `prev = 0` (3):
//   - Can we pick 5 after 3? Yes, because 5 > 3
//   - If picked: 1 + dp[3][2+1] = 1 + dp[3][3] = 1 + 0 = 1
//   - If not picked: dp[3][0+1] = dp[3][1] = 1
//   - Maximum = 1
//   - So `dp[2][1] = 1`
// - For `prev = -1` (no previous element):
//   - We can always pick with no previous constraint
//   - If picked: 1 + dp[3][2+1] = 1 + dp[3][3] = 1 + 0 = 1
//   - If not picked: dp[3][0] = 1
//   - Maximum = 1
//   - So `dp[2][0] = 1`

// ### DP Table after processing index 2:
// ```
//     prev  -1   0    1    2    3
// ind
//  0     ?    ?    ?    ?    ?
//  1     ?    ?    ?    ?    ?
//  2     1    1    1    X    X
//  3     1    1    1    0    X
//  4     0    0    0    0    0
// ```

// ## Step 3: Process Index 1 (Element = 1)

// For `ind = 1` (element = 1):
// - For `prev = 0` (3):
//   - Can we pick 1 after 3? No, because 1 < 3
//   - So we can only not pick: dp[2][0+1] = dp[2][1] = 1
//   - So `dp[1][1] = 1`
// - For `prev = -1` (no previous element):
//   - We can always pick with no previous constraint
//   - If picked: 1 + dp[2][1+1] = 1 + dp[2][2] = 1 + 1 = 2
//   - If not picked: dp[2][0] = 1
//   - Maximum = 2
//   - So `dp[1][0] = 2`

// ### DP Table after processing index 1:
// ```
//     prev  -1   0    1    2    3
// ind
//  0     ?    ?    ?    ?    ?
//  1     2    1    X    X    X
//  2     1    1    1    X    X
//  3     1    1    1    0    X
//  4     0    0    0    0    0
// ```

// ## Step 4: Process Index 0 (Element = 3)

// For `ind = 0` (element = 3):
// - For `prev = -1` (no previous element):
//   - We can always pick with no previous constraint
//   - If picked: 1 + dp[1][0+1] = 1 + dp[1][1] = 1 + 1 = 2
//   - If not picked: dp[1][0] = 2
//   - Maximum = 2
//   - So `dp[0][0] = 2`

// ### Final DP Table:
// ```
//     prev  -1   0    1    2    3
// ind
//  0     2    X    X    X    X
//  1     2    1    X    X    X
//  2     1    1    1    X    X
//  3     1    1    1    0    X
//  4     0    0    0    0    0
// ```

// ## Final Answer

// The LIS length is `dp[0][0] = 2`.

// ## How We Built This Solution

// 1. We started from the end of the array (bottom) and worked our way up to the beginning.
// 2. For each position:
//    - We considered all possible "previous" elements we might have picked.
//    - For each position and previous element:
//      - We calculated whether we could pick the current element
//      - We computed the max LIS using both choices: pick and not-pick
//      - We stored the best result in our table

// 3. Each cell `dp[ind][prev+1]` answers the question: "What's the longest increasing subsequence I can form starting at index `ind` if my last picked element was at index `prev`?"

// 4. The final answer `dp[0][0]` tells us the LIS length starting at index 0 with no previous element picked.

// This approach works because we're breaking down the problem into smaller subproblems and solving them first, then using those solutions to solve bigger subproblems.