#include <bits/stdc++.h>
using namespace std;

// Sum of Subarray minimums
// Will discuss the thought process thoroughly

// 1. Bruteforce thinking :
// we can find out all the subarrays and then we can find out their minimum and keep summing it

// T.C- O(n^2) S.C - O(1)

// Optimisation thinking:
// since we have to make it less than n ^ 2 so we can think of optimizing it by T.C

// but how can we optimize this?
// We need to think in the direction where we only need to traverse O(n) times

// ans : if we somehow cracked this that in how many subarrays this particular element is acting as minimum then we can solve this

// Now problem reduced to :
//  find an index is acting as minimum in how many subarrays
//  how we can do this?
// we can do this by finding the next and previous element which smaller than the current index element
// we need to find next/previous smaller element in an array
// T.C - O(n) and space complexity - O(n)

vector<int> prevSmaller(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prevArr(n, -1);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && arr[stk.top()] >= arr[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            prevArr[i] = stk.top();
        }
        stk.push(i);
    }
    return prevArr;
}

vector<int> nextSmaller(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nextArr(n, n);
    stack<int> stk;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[stk.top()] > arr[i]) // To handle duplicate we only have included > not >=
        // When you have duplicates, you need to decide which occurrence gets to "claim" the subarrays containing those duplicates.
        // consider this example [3,1,2,1] and perform dry run, a single sub array we be getting counted twice if we used >=
        {
            stk.pop();
        }
        if (!stk.empty())
            nextArr[i] = stk.top();
        stk.push(i);
    }
    return nextArr;
}

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    int MOD = 1e9 + 7;
    vector<int> prevArr = prevSmaller(arr);
    vector<int> nextArr = nextSmaller(arr);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int L = i - prevArr[i] - 1;
        int R = nextArr[i] - i - 1;
        long long count = (long long)(L + 1) * (R + 1);
        total = (total + (arr[i] * count) % MOD) % MOD;
    }
    return total;
}
int main()
{

    return 0;
}