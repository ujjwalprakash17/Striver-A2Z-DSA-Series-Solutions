#include <bits/stdc++.h>
using namespace std;

void solution(int ind, int target, vector<int> &candidates, vector<int> &temp, set<vector<int>> &result)
{
    if (ind == candidates.size())
    {
        if (target == 0)
        {
            sort(temp.begin(), temp.end());
            result.insert(temp);
        }
        return;
    }
    // not pick condition
    solution(ind + 1, target, candidates, temp, result);
    temp.push_back(candidates[ind]);
    // pick solution
    if (candidates[ind] <= target)
        solution(ind + 1, target - candidates[ind], candidates, temp, result);
    temp.pop_back();
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    set<vector<int>> result;
    vector<int> temp;
    solution(0, target, candidates, temp, result);
    vector<vector<int>> ans(result.begin(), result.end());
    return ans;
}

int main()
{

    return 0;
}