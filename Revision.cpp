#include <bits/stdc++.h>
using namespace std;
void generateAllSubsequences(int ind, vector<int> &temp, vector<vector<int>> &ans, vector<int> &arr)
{
    if (ind == arr.size())
    {
        if (temp.size() > 0)
        {
            ans.push_back(temp);
        }
        return;
    }
    //not pick 
    generateAllSubsequences(ind + 1, temp, ans, arr);
    //pick condition 
    temp.push_back(arr[ind]);
    generateAllSubsequences(ind + 1, temp, ans, arr);
    temp.pop_back();
}

int main()
{
    vector<int> sample = {1, 2, 3, 4};
    vector<vector<int>> ans;
    vector<int> temp;
    generateAllSubsequences(0, temp, ans, sample);
    int cnt = 0;
    for (auto it : ans)
    {
        cnt ++;
        for (int ele : it)
            cout << ele << " ";
        cout << endl;
    }
    cout << "total number of subsequences is " << cnt << endl;
    return 0;
}