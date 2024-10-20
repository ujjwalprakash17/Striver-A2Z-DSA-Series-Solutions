//Maximal Score After Applying K Operations
#include <bits/stdc++.h>
using namespace std;

long long maxKelements(vector<int> &nums, int k)
{
    priority_queue<int> pq;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
    }
    for (int i = 0; i < k; i++)
    {
        ans += pq.top();
        int currVal = ceil((double)pq.top() / (double)3);
        pq.pop();
        pq.push(currVal);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 10, 3, 3, 3};
    maxKelements(nums, 3);
    return 0;
}