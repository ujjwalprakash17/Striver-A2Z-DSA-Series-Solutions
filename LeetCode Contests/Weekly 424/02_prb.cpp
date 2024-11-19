//Zero Array Transformation I
#include <bits/stdc++.h>
using namespace std;

//Approach : Based on the inteval Value we need to find the number of occurance of elements in that interval for 
// Ex : [[0, 2] , [1,4], [0, 5], [3, 5]] is poore interval me 1 kitni baar hai 0, kitni baar
// also both inclusive
// Solution : har interval ke starting index ko +1 kro aur ending element + 1 ko -1 kro 
// for example 
// index -> [0] => val = 1;
// index -> [3] => val = -1;
// aur aisa krte krte phir har ek element ko array ke each element ke prefixSum ke value se replace krte chalo
    

bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    vector<int> freqInInterval(n + 1, 0);
    int m = queries.size();
    for (int i = 0; i < m; i++)
    {
        freqInInterval[queries[i][0]]++;
        freqInInterval[queries[i][1] + 1]--;
    }
    int prefixSum = freqInInterval[0];
    for(int i = 1; i < n ; i++)
    {
        freqInInterval[i] += prefixSum;
        prefixSum = freqInInterval[i];
    }
    for(int i = 0; i < n ; i++)
    {
        if(nums[i] > 0)
        {
            int diff  = (nums[i] - freqInInterval[i]);
            if(diff <= 0) return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}