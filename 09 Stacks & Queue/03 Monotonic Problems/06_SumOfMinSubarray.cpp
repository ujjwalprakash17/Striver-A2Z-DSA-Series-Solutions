#include <bits/stdc++.h>
using namespace std;
// Thought process :
// Bruteforce : we can find using two loops T.C - O(n * n)

// <-----------------OPTIMISED APPROACH--------------->

// Thought process : shift the way of thinking as ki for a particular index, in how many subarrays this is minimum
//  toh hmne ye pta kr liya ki kitne subarrays me yeh minimum hai toh hm formulae aise likhenge ki
//  no of subarrays (in which arr[i] is minimum) * arr[i] for all i from 1 to n

// now our problem reduced to how do we find the number of subarrays in which this is minimum?

// hm left me dekhte jayenge ki jb tak current value se koi chhota na mil jaye, same hm right me bhi dekhte jayenge jb tak isse koi chhota na mil jaye
// (this means we need to find next immediate smaller and prev immediate smaller) for each index
// aur agar ye nikal liya toh kaam ban jayega kaise ?
// aise :- ki individual contribution will be arr[i] * (L + 1) * (R + 1)

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

int main()
{
    vector<int> sample = {9, 12, 10, 15, 17, 7};
    cout << sumSubarrayMins(sample) << "\n";

    return 0;
}