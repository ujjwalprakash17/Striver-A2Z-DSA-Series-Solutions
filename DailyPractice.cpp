#include <bits/stdc++.h>
using namespace std;

int lengthAfterTransformations(string s, int t)
{
    vector<int> strFreq(26, 0);
    for (char ch : s)
    {
        strFreq[ch-'a']++;
    }

    for (int i = 0; i < t; i++)
    {
        vector<int> nextFreq(26, 0);
        for (int j = 0; j < 26; j++)
        {
            if(j == 25){
                nextFreq[0] += strFreq[j];
                nextFreq[1] += strFreq[j];
            }else{
                nextFreq[j+1] = strFreq[j];
            }    
        }
        strFreq = nextFreq;
    }
    int mod = 1e9 + 7;
    long long ans = 0;
    for(int val : strFreq)
    {
        ans += val;
    }
    return ans % mod;
}

int main()
{

    return 0;
}