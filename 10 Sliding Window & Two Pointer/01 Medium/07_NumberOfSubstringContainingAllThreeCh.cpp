#include <bits/stdc++.h>
using namespace std;

// Trick for the problem : since the string only contains of a, b and c, so we can treat this problem as
// no of subarrays with K distinct elements

int countSubStringWithAtMostK(string s, int k)
{
    int left = 0;
    int n = s.length();
    unordered_map<char, int> mp;
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
        ans += right - left + 1;
    }
    return ans;
}

int numberOfSubstrings(string s)
{
    return countSubStringWithAtMostK(s, 3) - countSubStringWithAtMostK(s, 2);
}

//Another approach : what if we have chars other than a, b and c in the string then if we are asked to find the number of substring where at least each of a, b and c must be present in the substring

int main()
{

    return 0;
}