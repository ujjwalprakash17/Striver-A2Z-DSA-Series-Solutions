#include<bits/stdc++.h>
using namespace std;
int maxLength(vector<int> &arr)
{
    // code here
    unordered_map<int, int> mp;
    int ans = 0;
    int n = arr.size();
    int prefixSum = 0;
    mp[0] = -1;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (mp.find(prefixSum) != mp.end())
        {
            ans = max(ans, i - mp[prefixSum]);
        }
        else
        {
            mp[prefixSum] = i;
        }
    }
    return ans;
}

int main()
{
    vector<int> sample = {-31, -48, -90, 54, 20, 95, 6, -86, 22};
    cout << maxLength(sample);

    return 0;
}