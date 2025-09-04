#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    unordered_map<char, int> required, window;
    int n = s.size(), m = t.size();
    int left = 0, startIndex = -1, count = 0, minLength = INT_MAX;
    for (char ch : t)
        required[ch]++;
    for (int right = 0; right < n; right++)
    {
        // here we did the updation part - taiyari
        window[s[right]]++;
        if (required.count(s[right]) && window[s[right]] == required[s[right]])
            count++;
        // when we are ready, then start shrinking the window
        while (count == required.size())
        {
            // current length le lo
            int currLen = right - left + 1;
            if (currLen < minLength)
            {
                minLength = currLen;
                startIndex = left;
            }
            // shrink the window
            window[s[left]]--;
            // now shrink the window and keep in mind that if our window looses the elements that is in requied as well, then we need to decrease our count
            if (required.count(s[left]) && window[s[left]] < required[s[left]])
                count--;
            left++;
        }
    }
    //check if startIndex is still -1
    if(startIndex == -1) return "";
    return s.substr(startIndex, minLength);
}

int main()
{

    return 0;
}