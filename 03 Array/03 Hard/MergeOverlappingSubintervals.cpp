#include <bits/stdc++.h>
using namespace std;

// //Approach : 
// 1. sort the intervals first
// 2. check first endtime and nexts start time if both are overlapping then merge threadmbcinfostruct
// 3. if not overlapping then create a new interval and then check again and so on...
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    for(int i = 0; i < intervals.size(); i++)
    {
        int startTime = intervals[i][0];
        int endTime = intervals[i][1];
        if(result.empty() || result.back()[1] < startTime)
        {
            result.push_back({startTime, endTime});
        }else{
            result.back()[1] = max(result.back()[1], endTime);
        }
    }
    return result;
}

int main()
{

    return 0;
}