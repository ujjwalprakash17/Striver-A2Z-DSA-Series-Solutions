#include <bits/stdc++.h>
using namespace std;

    int findMinSubarray(vector<int> &nums, int rem)
    {
        int n = nums.size() ; 
        long long prefixSum = 0;
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        for(int i = 0; i < n ; i++)
        {
            prefixSum += nums[i];
            int val = prefixSum - rem;
            if(mp.find(val) != mp.end()){
                ans = min(ans, i - mp[val]);
            }
            mp[prefixSum] = i;
        }
        return ans;
    }
    void minSubarray(vector<int> &nums, int p)

    {
        long long sum = 0;
        for(int i = 0; i < nums.size() ; i++)
        {
            sum += nums[i];
        }
        int rem = sum % p;
        findMinSubarray(nums, rem);
    }


int main()
{
    vector<int> sample = {26,19,11,14,18,4,7,1,30,23,19,8,10,6,26,3};
    int p = 26;
    minSubarray(sample, p);
    

    return 0;
}