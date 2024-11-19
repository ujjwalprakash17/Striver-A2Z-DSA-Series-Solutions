#include <bits/stdc++.h>
using namespace std;

int shortestSubarray(vector<int> &nums, int k)
{
    int prefixSum = 0;
    int ans = INT_MAX;
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        prefixSum += nums[i];
        if (prefixSum == k)
        {
            ans = i + 1;
        }
        int rem = prefixSum - k;
        // found
        if (mp.find(rem) != mp.end())
        {
            //do something
        }
        // not found
        else if(mp.find(rem) != mp.end())
        {
            //do something
        }
    }
}

int main()
{

    return 0;
}