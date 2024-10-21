#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> store;
    int n = nums.size();
    if(n == 0) return 0;
    //store everything in set
    for(int i : nums)
    {
        store.insert(i);
    }
    //now find out starting position for a sequence, by looking for starting value
    int ans = 1;
    for(auto it : store)
    {
        if(store.find(it-1) == store.end())
        {
            int cnt = 1;
            int x = it;
            while(store.find(x+1) != store.end())
            {
                cnt++;
                x++;
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}

int main()
{

    return 0;
}