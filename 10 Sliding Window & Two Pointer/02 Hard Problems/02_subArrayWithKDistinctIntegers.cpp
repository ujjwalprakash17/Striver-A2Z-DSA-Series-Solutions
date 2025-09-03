#include <bits/stdc++.h>
using namespace std;

// Identification of this problem :
// see in order to count the number of distinct elements we can't directly use 2 pointers because it will it generates ambiguity
// so we came down to the concepts that shows monotonic behaviour where
// count of subarray (with exactly k distinct elements ) = count of subarray(with at most k distinct element) - count of subarray (with at most k - 1 distinct element)
//it is very important to add the edge case that is k == 0

int countForAtMostKDiff(vector<int> &nums, int k)
{
    if (k == 0)
        return 0;
    int n = nums.size();
    int left = 0;
    unordered_map<int, int> mp;
    int subArrCnt = 0;
    for (int right = 0; right < n; right++)
    {
        int currEle = nums[right];
        mp[currEle]++;
        while (mp.size() > k)
        {
            mp[nums[left]]--;
            if (mp[nums[left]] == 0)
            {
                mp.erase(nums[left]);
            }
            left++;
        }
        subArrCnt += right - left + 1;
    }
    return subArrCnt;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return countForAtMostKDiff(nums, k) - countForAtMostKDiff(nums, k - 1);
}

int main()
{

    return 0;
}