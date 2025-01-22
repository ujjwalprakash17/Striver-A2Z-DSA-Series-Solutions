#include <bits/stdc++.h>
using namespace std;

int Solution(vector<vector<int>> &A)
{
    int n = A.size();
    vector<int> startTime, endTime;
    for (auto it : A)
    {
        startTime.push_back(it[0]);
        endTime.push_back(it[1]);
    }
    sort(startTime.begin(), startTime.end());
    sort(endTime.begin(), endTime.end());
    int i = 0, j = 0;
    int rooms = 0, max_rooms = INT_MIN;
    while (i < n && j < n)
    {
        if (startTime[i] < endTime[j])
        {
            rooms++;
            i++;
        }
        else
        {
            rooms--;
            j++;
        }
        max_rooms = max(rooms, max_rooms);
    }
    return max_rooms;
}

int main()
{

    return 0;
}