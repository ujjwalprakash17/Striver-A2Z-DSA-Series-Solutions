#include <bits/stdc++.h>
using namespace std;

// Approach for this problem is :
//  1. increase the window length till the subsequence is found, direction : left to right
//  2. as we found our correct window length then we will start shrinking from right to left
//  3. And then we will update our min Length value
// 4. as soon as we found a valid substring with minimum length then we will update our min length and ans array
// 5. after the updatation process is complete then we will move the right again starting from left + 1

string minWindow(string s, string t)
{
    int n = s.size(), m = t.size();
    string ans = "";
    int tPointer = 0;
    int minLength = INT_MAX;
    for (int right = 0; right < n; right++)
    {
        if (s[right] == t[tPointer])
        {
            tPointer++;
            // now if t pointer reaches to the end of string t
            if (tPointer == m)
            {
                int start = right; // since right hasn't been incremented
                int end = right;
                // now we will start traversing backwards
                tPointer = m - 1; // bring tPointer to the end of string
                while (start >= 0)
                {
                    if (t[tPointer] == s[start])
                    {
                        tPointer--;
                    }
                    // if before start reaches to 0, if tPointer reaches to start of t
                    if (tPointer < 0)
                        break;
                    start--;
                }
                // now our end is at end of substring and start is at start of substring then
                if (end - start + 1 < minLength)
                {
                    minLength = end - start + 1;
                    ans = s.substr(start, minLength);
                }
                // we need to reset our right and t pointer
                right = start; // now we will check for the elements next to start
                tPointer = 0;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}