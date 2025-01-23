#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), comp);
}

int main()
{
    vector<vector<int>> merge = {{1,4}, {2, 6}, {4, 1}};
    sort(merge.begin(), merge.end());
    for(auto it : merge){
        cout << it[0] << " " << it[1] << "\n";
    }

    return 0;
}