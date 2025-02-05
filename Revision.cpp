#include <bits/stdc++.h>
using namespace std;

int maxAscendingSum(vector<int> &nums)
{
    int n = nums.size();
    int ans = nums[0];
    int sum = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
            continue;
        if (nums[i] > nums[i - 1])
            sum += nums[i];
        else if (nums[i] < nums[i - 1])
            sum = nums[i];
        ans = max(ans, sum);
    }
    return ans;
}

int main()
{
    vector<int> sample = {5,5,6,6,6,9,1,2};
    cout << maxAscendingSum(sample);

    return 0;
}