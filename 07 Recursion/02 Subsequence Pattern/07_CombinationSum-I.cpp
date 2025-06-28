#include <bits/stdc++.h>
using namespace std;

void solution(int ind, vector<int> &candidates, int target, vector<int> temp, vector<vector<int>> &result)
{
    if (ind == candidates.size())
    {
        if (target == 0)
        {
            result.push_back(temp);
        }
        return;
    }

    // notpick situation
    solution(ind + 1, candidates, target, temp, result);
    // pick situationf
    if (candidates[ind] <= target)
    {
        temp.push_back(candidates[ind]);
        solution(ind, candidates, target - candidates[ind], temp, result);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> result;
    vector<int> temp;
    solution(0, candidates, target, temp, result);
    return result;
}

int main()
{

    return 0;
}