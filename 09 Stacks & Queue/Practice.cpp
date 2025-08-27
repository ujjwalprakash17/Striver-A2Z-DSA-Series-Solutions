#include <bits/stdc++.h>
using namespace std;

// Approach:
// we need to find prev max and next max and then we need to find min(prevMax, nextMax) - height[i]

vector<int> computePrefixMax(vector<int> &height)
{
    int n = height.size();
    vector<int> prevMaxArr(n, -1);
    prevMaxArr[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        prevMaxArr[i] = max(prevMaxArr[i - 1], height[i]);
    }

    return prevMaxArr;
}

vector<int> computeSuffixMax(vector<int> &height)
{
    int n = height.size();
    vector<int> nextMaxArr(n, -1);
    nextMaxArr[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        nextMaxArr[i] = max(nextMaxArr[i + 1], height[i]);
    }

    return nextMaxArr;
}

int trap(vector<int> &height)
{
    int total = 0;
    vector<int> prevMaxArr = computePrefixMax(height);
    vector<int> nextMaxArr = computeSuffixMax(height);
    int n = height.size();
    for (int i = 0; i < n; i++)
    {
        int leftMax = prevMaxArr[i];
        int rightMax = nextMaxArr[i];
        total += min(leftMax, rightMax) - height[i];
    }
    return total;
}

int main()
{

    return 0;
}