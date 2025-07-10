#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solution(int ind, vector<int> &nums, vector<int> temp,
                  set<vector<int>> &tempResult)
    {
        if (ind == nums.size())
        {
            tempResult.insert(temp);
            return;
        }
        // pick element
        temp.push_back(nums[ind]);
        solution(ind + 1, nums, temp, tempResult);
        temp.pop_back();
        solution(ind + 1, nums, temp, tempResult);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> tempResult;
        vector<int> temp;
        solution(0, nums, temp, tempResult);
        vector<vector<int>> result(tempResult.begin(), tempResult.end());
        return result;
    }
};

int main()
{

    return 0;
}