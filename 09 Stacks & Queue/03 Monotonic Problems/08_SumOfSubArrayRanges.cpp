#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prevSmallerArr(n, -1);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && arr[stk.top()] >= arr[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            prevSmallerArr[i] = stk.top();
        }
        stk.push(i);
    }
    return prevSmallerArr;
}
vector<int> nextSmaller(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nextSmallerArr(n, n);
    stack<int> stk;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[stk.top()] > arr[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            nextSmallerArr[i] = stk.top();
        }
        stk.push(i);
    }
    return nextSmallerArr;
}
int sumSubarrayMins(vector<int> &arr)
{
    int MOD = 1e9 + 7;
    int result = 0;
    int n = arr.size();
    vector<int> prevArray = prevSmaller(arr);
    vector<int> nextArray = nextSmaller(arr);
    for (int i = 0; i < n; i++)
    {
        int L = i - prevArray[i] - 1;
        int R = nextArray[i] - i - 1;
        long long count = (long long)(L + 1) * (R + 1);
        result = (result + (count * arr[i]) % MOD) % MOD;
    }
    return result;
}

vector<int> prevGreater(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prevGreaterArr(n, -1);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && arr[stk.top()] <= arr[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            prevGreaterArr[i] = stk.top();
        }
        stk.push(i);
    }
    return prevGreaterArr;
}

vector<int> nextGreater(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nextGreaterArr(n, n);
    stack<int> stk;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[stk.top()] < arr[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            nextGreaterArr[i] = stk.top();
        }
        stk.push(i);
    }
    return nextGreaterArr;
}

int sumSubArrayMax(vector<int> &arr)
{
    int MOD = 1e9 + 7;
    long long result = 0;
    int n = arr.size();
    vector<int> prevArray = prevGreater(arr);
    vector<int> nextArray = nextGreater(arr);
    for (int i = 0; i < n; i++)
    {
        long long L = i - prevArray[i];
        long long R = nextArray[i] - i;
        long long count = L * R;
        result = (result + (count * arr[i]) % MOD) % MOD;
    }
    return (int)result;
}

// ---------------- Final Answer ------------------

long long subArrayRanges(vector<int> &nums)
{
    return (long long)sumSubArrayMax(nums) - (long long)sumSubarrayMins(nums);
}

int main()
{

    return 0;
}