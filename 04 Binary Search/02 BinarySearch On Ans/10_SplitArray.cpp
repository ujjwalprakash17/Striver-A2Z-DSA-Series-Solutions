#include <bits/stdc++.h>
using namespace std;

bool checkValid(vector<int> &nums, int k, int val)
{
    int cnt = 1, sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (sum + nums[i] <= val)
        {
            sum += nums[i];
        }
        else
        {
            cnt++;
            sum = nums[i];
        }
        if (cnt > k)
        {
            return false;
        }
    }
    return true;
}
int splitArray(vector<int> &nums, int k)
{
    int s = *max_element(nums.begin(), nums.end()), e = accumulate(nums.begin(), nums.end(), 0);
    int ans = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (checkValid(nums, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> sample = {1,4,4};
    splitArray(sample, 3);

    return 0;
}