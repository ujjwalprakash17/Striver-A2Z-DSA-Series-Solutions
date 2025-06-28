#include <bits/stdc++.h>
using namespace std;

// bool solution(int ind, vector<int> &arr, int target, vector<vector<int>> &dp)
// {
//     if (ind == arr.size())
//     {
//         return target == 0;
//     }

//     if (dp[ind][target] != -1)
//         return dp[ind][target];

//     bool notPick = solution(ind + 1, arr, target, dp);
//     bool pick = false;
//     if (arr[ind] <= target)
//     {
//         pick = solution(ind + 1, arr, target - arr[ind], dp);
//     }

//     return dp[ind][target] = pick || notPick;
// }

// bool checkSubsequenceSum(int n, vector<int> &arr, int k)
// {
//     // Code here
//     vector<vector<int>> dp(n, vector<int>(k + 1, -1));
//     return solution(0, arr, k, dp);
// }

vector<int> maxSubsequence(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        if (pq.size() < k)
        {
            pq.push({nums[i], i});
        }
        else if (nums[i] > pq.top().first)
        {
            pq.pop();
            pq.push({nums[i], i});
        }
    }

    // Extract all elements from priority queue into a vector
    vector<pair<int, int>> selected;
    while (!pq.empty())
    {
        selected.push_back(pq.top());
        pq.pop();
    }

    // Sort by index (second element of pair)
    sort(selected.begin(), selected.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
             return a.second < b.second; // Sort by index in ascending order
         });

    // Build result vector with just the values
    vector<int> result;
    for (auto &p : selected)
    {
        result.push_back(p.first); // Add the value (not the index)
    }

    return result;
}

int main()
{

    return 0;
}