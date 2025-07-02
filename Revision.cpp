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


1. sort(nums.begin(), nums.end(), [](const int &a, const int &b){
    return a % 10 < b % 10;
});

2. a. sort(students.begin(), students.end(), [](const pair<string, int> &a, const pair<string, int> &b){
    if(a.second != b.second) 
    return a.second > b.second;
    return a.first < a.second;
});

3. sort(arrays.begin(), arrays.end(), [](const vector<int> &a, const vector<int>&b){
    long long sumOfA = accumulate(a.begin(), a.end(), 0LL);
    long long sumOfb = accumulate(b.begin(), b.end(), 0LL);
    return sumOfA > sumOfb;
});

int findVowelCnt(string &s)
{
    int cnt = 0;
    for(char ch : s)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') cnt++;
    }
}

4. sort(words.begin(), words.end(), [](const string &a, const string &b){
    int vowelCntOfA = findVowelCnt(a); 
    int vowelCntOfB = findVowelCnt(b); 
    return vowelCntOfA < vowelCntOfB;
});