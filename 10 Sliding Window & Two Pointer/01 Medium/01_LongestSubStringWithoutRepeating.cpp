#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    // edge case
    if (s.size() == 0)
        return 0;

    unordered_map<char, int> mp;
    int left = 0, right = 0;
    int ans = INT_MIN;
    while (right < s.size())
    {
        // if found
        if (mp.find(s[right]) != mp.end())
        {
            int index = mp[s[right]];
            while(left <= index)
            {
                mp.erase(s[left]);
                left++;
            }
            continue;
        }
        // if not found
        else
        {
            mp[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
        right++;
    }
    return ans;
}



int main()
{
    lengthOfLongestSubstring("abcabcbb");
    return 0;
}