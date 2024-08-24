#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
    int left = 0, right = 0;
    int n = s.size();
    while (right < n)
    {
        if(s[left] != s[right]) cnt++;
        while(cnt > k)
        {
            if(s[left])
            left++;
        }
        right++;
    }
    
}

int main()
{

    return 0;
}