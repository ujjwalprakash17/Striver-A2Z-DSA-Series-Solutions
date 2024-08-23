#include <bits/stdc++.h>
using namespace std;

void solution(vector<int> temp, int ind, int n, vector<vector<int>> &result, vector<int> nums)
{
    //base case 
    if(ind == n)
    {
        result.push_back(temp);
        return ;
    }
    //take case 
    temp.push_back(nums[ind]);
    solution(temp, ind + 1 , n , result, nums);
    //not take case 
    temp.pop_back();
    solution(temp, ind + 1 , n , result, nums);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> temp;
    solution(temp, 0, nums.size(), result, nums);
    return result;
}

int main()
{

    return 0;
}