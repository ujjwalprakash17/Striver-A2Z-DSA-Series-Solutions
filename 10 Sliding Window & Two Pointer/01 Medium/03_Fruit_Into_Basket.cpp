#include <bits/stdc++.h>
using namespace std;

//approach : jb jb hamare do type me se koi ek type milega hm add kregne map aur jaise hi 3isra type milega hm map se ek type remove kr denge

int totalFruits(vector<int> &arr) {
    unordered_map<int, int>mp;
    int left = 0, right = 0;
    int ans = 0, cnt = 0;
    while (right < arr.size())
    {
        mp[arr[right]]++;
        //if size greater than 2
        while(mp.size() > 2)
        {
            mp[arr[left]]--;
            if(mp[arr[left]] == 0)
            mp.erase(arr[left]);
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

int main()
{

    return 0;
}