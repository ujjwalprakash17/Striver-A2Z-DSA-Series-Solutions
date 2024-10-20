#include <bits/stdc++.h>
using namespace std;

bool solution(int ind, int target, vector<int> &arr, vector<vector<int> > &dp)
{
    // base case
    if (target == 0)
        return true;
    if (ind == 0) return (arr[0] == target);
    //dp condition check
    if(dp[ind][target] != -1) return dp[ind][target] == 0 ? false : true;
    
    bool notPick = solution(ind - 1, target, arr, dp);
    bool pick = false;
    if (arr[ind] <= target) pick = solution(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] =  (pick || notPick) ? true : false;
}

bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    int n = arr.size();
    vector<vector<int> > dp(n, vector<int>(sum + 1, -1));
    return solution(n - 1, sum, arr, dp);
}

int main()
{


    return 0;
}