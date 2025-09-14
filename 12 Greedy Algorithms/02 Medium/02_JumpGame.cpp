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
//Concept :
// Up to now, what is the farthest place I could possibly reach?
//if at some point I am at where which in ahead of my farthest this means I have exceeded my farthest limit means I can't travel any more and I haven't reached to end 

// Suppose at some index i, we realize:
// i > farthest
// That means:
// The farthest we could reach before was behind i.
// We are now “stuck” — we cannot even stand on i.
// If you’re stuck before the last index, you will never reach the end → return false.

int main()
{

    return 0;
}
