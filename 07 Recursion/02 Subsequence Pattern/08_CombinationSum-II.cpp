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


// High-Level Approach for Combination Sum II:
// Goal: Find all unique combinations where numbers sum to target, each number used at most once.
// Key Steps:

// Sort the array - groups duplicates together
// Use backtracking - try including/excluding each element
// Skip duplicates at same level - when you have [1,1,2] and you skip the first 1, also skip the second 1 at that same recursion level
// Early termination - stop exploring when current number > remaining target

// Core Logic: At each position, decide whether to include the current number or not. If you include it, reduce the target and move to next position. If you skip it, also skip all identical numbers at the same level to avoid duplicate combinations.
// Why it works: Sorting + level-wise duplicate skipping ensures you get all unique combinations without needing expensive set operations to filter duplicates later.