#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str)
{
    // Write your code here
    int n = str.size();
    unordered_map<char, int> mp;
    int left = 0;
    int ans = 0;
    for (int right = 0; right < n; right++)
    {
        mp[str[right]]++;
        while (mp.size() > k)
        {
            mp[str[left]]--;
            if (mp[str[left]] == 0)
            {
                mp.erase(str[left]);
            }
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}

int main()
{
    string s = "abbbbbbc";
    int k = 2;
    cout << kDistinctChars(k, s);

    return 0;
}