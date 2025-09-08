#include <bits/stdc++.h>
using namespace std;

int maxMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++)
    {
        meetings.push_back({start[i], end[i]});
    }
    sort(meetings.begin(), meetings.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.second < b.second; });
    int cnt = 1;
    int prevEndTime = meetings[0].second;
    for (int i = 1; i < n; i++)
    {
        if (meetings[i].first > prevEndTime)
        {
            cnt++;
            prevEndTime = meetings[i].second;
        }
    }
    return cnt;
}

int main()
{

    return 0;
}