#include <bits/stdc++.h>
using namespace std;
// Approach : 
// hm dono array ko sort kr lenge because the order is not that important 
// aur approach very simple hai size array ke element agar greed array ke element se greater than or equal to left++ & right ++ nhi toh 
// look for bigger size by left++..
int findContentChildren(vector<int>& g, vector<int>& s) {
        int left = 0, right = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(left < s.size() && right < g.size()){
            if(s[left] >= g[right]){
                left++,right++;
            }
            else left++;
        }
        return right;
    }

int main()
{
    
    return 0;
}