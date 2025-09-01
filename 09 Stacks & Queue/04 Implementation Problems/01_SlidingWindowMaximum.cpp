#include <bits/stdc++.h>
using namespace std;

// Approach : we will think about having a stack with a monotonic decreasing property, but the thing is
// we can't pop elements from back in stack
// that is we will use dq as stack with poping element from front end
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] <= nums[i]) // <= for handling duplicates
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}
//Time Complexity : O(n), Space Complexity : O(n-k)

int main()
{

    return 0;
}