#include <bits/stdc++.h>
using namespace std;

//its the same as mine energy carry wala idea, where we were carrying our energy and kept on decreasing

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int farthest = 0;
    for(int i = 0 ; i < nums.size();  i++)
    {
        if(i > farthest) return false;
        farthest = max(farthest, i + nums[i]);    //iska simple mtlb hai ki what is the maximum till now, jisme hm har index se kitna aage jaa sakte hain ye calculate kr rhe hain (i + curr[i]) = is index se kitna aur aage ja sakte hain
    }
    return  true;
}

int main()
{

    return 0;
}
