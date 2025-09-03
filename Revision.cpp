#include <bits/stdc++.h>
using namespace std;

// we are using the concept:
// subarrays (where sum = 2) = subarrays(sum <= 2) - subarrays(sum <= 1)
int countWithAtMost(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    int left = 0;
    int n = nums.size();
    int ans = 0;
    int sum = 0;
    for (int right = 0; right < n; right++)
    {
        sum += nums[right];
        while (sum > goal)
        {
            sum -= nums[left];
            left++;
        }
        ans += right - left + 1;
    }
    return ans;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return countWithAtMost(nums, goal) - countWithAtMost(nums, goal - 1);
}

int main()
{
    vector<int> sample = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};

    return 0;
}