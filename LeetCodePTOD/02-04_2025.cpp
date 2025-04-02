// Maximum ordered triplet - I and II
#include <bits/stdc++.h>
using namespace std;

// //intuition 
// we need to minimize the value of y so that the value of x could be as max as possible
// and also we need to maximize both of x and y so that we could get the max value possible

// // Approach
// 1. we need to calculate the first the right side maximum of respective to each of the max_element
// 2. then we will try to calculate the left hand side maximum based on the (x-y) and the rightMax of each element

long long maximumTripletValue(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return 0; // Handle edge cases where triplet is not possible

    // Step 1: Precompute `max_right`
    vector<int> max_right(n);
    max_right[n - 1] = nums[n - 1]; // Initialize last element of max_right
    for (int i = n - 2; i >= 0;
         i--)
    { // Correct range for backward iteration
        max_right[i] = max(nums[i + 1], max_right[i + 1]);
    }

    // Step 2: Traverse from left to right to compute maximum triplet value
    int max_left = nums[0];
    long long ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        long long temp = 1LL * (max_left - nums[i]) * max_right[i];
        if (temp >= 0)
            ans = max(temp, ans);
        max_left = max(max_left, nums[i]);
    }
    return ans;
}
int main()
{
    vector<int> sample = {12, 6, 1, 2, 7};
    cout << maximumTripletValue(sample);

    return 0;
}