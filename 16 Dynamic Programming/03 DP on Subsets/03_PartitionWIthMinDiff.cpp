#include <bits/stdc++.h>
using namespace std;



int solution(int ind, int sum, int cnt, vector<int> &arr)
{
    if(ind < 0) return 1e8;
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int n = arr.size();
    if(cnt == n / 2){
        int remDiff = totalSum - sum;
        return abs(remDiff - sum); 
    }
    int notPick = solution(ind - 1, sum, cnt, arr);

    int pick = solution(ind - 1, sum + arr[ind], cnt + 1, arr);
    
    return min(pick, notPick);
}
int minimumDifference(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int cnt = (n / 2 )+ 1;
    return solution(n-1, 0, 0, nums);
}


// int solution(int ind, int sum, int cnt, vector<int> &arr,  vector<vector<vector<int>>> &dp)
// {
//     // Base case: If we've reached the beginning of the array
//     if(ind < 0) {
//         // If we don't have exactly n/2 elements, return a large value
//         if(cnt != arr.size() / 2) return 1e8;
//         // Calculate the difference between the two subsets
//         int totalSum = accumulate(arr.begin(), arr.end(), 0);
//         return abs((totalSum - sum) - sum);
//     }
    
//     // If we've already computed this state, return the cached result
//     if(dp[ind][sum][cnt] != -1) return dp[ind][sum][cnt];
    
//     // Option 1: Skip the current element
//     int notPick = solution(ind - 1, sum, cnt, arr, dp);
    
//     // Option 2: Pick the current element (only if we haven't picked n/2 elements yet)
//     int pick = 1e8;
//     if(cnt < arr.size() / 2) {
//         pick = solution(ind - 1, sum + arr[ind], cnt + 1, arr, dp);
//     }
    
//     // Return the minimum of the two options and cache the result
//     return dp[ind][sum][cnt] = min(pick, notPick);
// }

// int minimumDifference(vector<int> &nums)
// {
//     int n = nums.size();
//     int totalSum = accumulate(nums.begin(), nums.end(), 0);
    
//     // Create a 3D DP array with dimensions: index, sum, count
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(totalSum + 1, vector<int>(n/2 + 1, -1)));
    
//     return solution(n-1, 0, 0, nums, dp);
// }

int main()
{
    vector<int> sample = {-36, 36};
    minimumDifference(sample);

    return 0;
}