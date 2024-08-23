#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &nums, int s, int e, int target)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (target == nums[mid])
            return true;
        else if (target > nums[mid])
            s = mid + 1;
        else
            e = mid - 1;
    }
    return false;
}
int getPivot(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
            return i + 1;
    }
    return 0;
}
bool search(vector<int> &nums, int target)
{
    int n = nums.size();
    int pivotInd = getPivot(nums);
    if (target > nums[pivotInd] && target > nums[n - 1])
        return binarySearch(nums, 0, pivotInd - 1, target);
    return binarySearch(nums, pivotInd, n - 1, target);
}

int main()
{

    return 0;
}