#include <bits/stdc++.h>
using namespace std;

int maxMeetings(int n, int start[], int end[])
{
    // Your code here
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        vec[i] = make_pair(start[i], end[i]);
    }
    sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        return a.second < b.second;
    });
    int cnt = 1;
    int prev = vec[0].second;
    for(int i = 1; i < n; i++)
    {
        if(vec[i].first > prev)
        {
            cnt++;
            prev = vec[i].second;
        }
    }
    return cnt;

}

int main()
{
    int n = 6;;
    int arr1[] = {1, 3, 0, 5, 8, 5};
    int arr2[] = {2, 4, 6, 7, 9, 9};
    cout << maxMeetings(n, arr1, arr2) << endl;
    return 0;
}