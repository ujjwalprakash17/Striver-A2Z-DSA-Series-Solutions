#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{
    int n = nums.size();
    int farthest = 0;
    int cnt = 0;
    int end = 0;
    for(int i = 0 ; i < nums.size();  i++)
    {
        farthest = max(farthest, i + nums[i]);
        if(i == end)
        {
            cnt++;
            end = farthest;
        }
    }
    return  cnt;
}

int main() {
    vector<int> sample = {2, 3, 1, 1, 4};
    jump(sample);
    return 0;
}