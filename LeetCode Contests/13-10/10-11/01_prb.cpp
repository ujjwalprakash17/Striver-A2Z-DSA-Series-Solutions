#include <bits/stdc++.h>
using namespace std;

int minimumSubarrayLength(vector<int> &nums, int k)
{
    int left = 0, right = 0;
    long long orVal = 0; // Use long long to prevent overflow
    int n = nums.size();
    int ans = INT_MAX;

    while (right < n)
    {
        orVal |= nums[right];
        while (orVal >= k && left <= right)
        {
            ans = min(ans, right - left + 1);
            orVal ^= nums[left];
            left++;
        }
        right++;
    }

    return ans == INT_MAX ? -1
                          : ans; // Return -1 if no valid subarray is found
}

int main()
{
    vector<int> sample = {1, 2, 32, 21};
    int k = 55;
    cout << minimumSubarrayLength(sample, k);
    return 0;
}