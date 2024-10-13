#include <bits/stdc++.h>
using namespace std;

int sumOfTopXMostFreq(vector<int> &nums, int x, unordered_map<int, int> &mp)
{
    // create a min_heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (const auto &it : mp)
    {
        pq.push({it.second, it.first});
        if (pq.size() > x)
            pq.pop();
    }
    
    int result = 0;
    while (!pq.empty())
    {
        result += (pq.top().second * pq.top().first);
        pq.pop();
    }
    return result;
}

vector<int> findXSum(vector<int> &nums, int k, int x)
{
    // we need to find the frequency of first k elements
    unordered_map<int, int> mp;
    for (int i = 0; i < k ; i++)
        mp[nums[i]]++;
    // we need a priority queue to find top x most frequent elements
    vector<int> ans;
    int left = 0, right = k;
    while (right <= nums.size())
    {
        int currVal = sumOfTopXMostFreq(nums, x, mp);
        ans.push_back(currVal);
        if(left < nums.size())
        mp[nums[left++]]--;
        if(right < nums.size())
        mp[nums[right++]]++;
    }
    return ans;
}
int main()
{
    vector<int> sample = {1, 1, 2, 2, 3, 4, 2, 3};
    int k = 6;
    int x = 2;
    vector<int> ans = findXSum(sample, k, x);
    for (int i : ans)
        cout << i << " ";
    return 0;
}