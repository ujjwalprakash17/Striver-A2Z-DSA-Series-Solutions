#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string &s, int k)
{
    // code here
    int n = s.length();
    unordered_map<char, int> mp;
    int left = 0;
    int ans = 0;
    for (int right = 0; right < n; right++)
    {
        mp[s[right]]++;
        while (mp.size() > k)
        {
            mp[s[left]]--;
            if (mp[s[left]] == 0)
            {
                mp.erase(s[left]);
            }
            left++;
        }
        if (mp.size() == k)
            ans = max(ans, right - left + 1);
    }
    return ans ? ans : -1;
}

int main()
{

    return 0;
}