#include <bits/stdc++.h>

using namespace std;
int getKthLargest(vector<int> &arr, int k)

{
    vector<int> sum;
    for (int i = 0; i < arr.size(); i++)
    {
        int val = 0;
        for (int j = i; j < arr.size(); j++)
        {
            val = val + arr[j];
            sum.push_back(val);
        }
    }
    sort(sum.begin(), sum.end(), greater<int>());
    return sum[k - 1];
}

int getKthLargest(vector<int> &arr, int k)
{
    //	Write your code here.
    vector<int> store;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            store.push_back(sum);
        }
    }
    sort(store.begin(), store.end(), greater<int>());
    // reverse(store.begin(), store.end());
    return store[k - 1];
}

int main()
{

    return 0;
}