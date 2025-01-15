#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int i = 0, j = i + 1, k = n -1;
    set<vector<int>> ans;
    while((k-i) > 1)
    {
        while(j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0)
            {
                j++;
            }
            else if(sum > 0)
            {
                k--;
            }
            else{
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.insert(temp);
            }
        }
        i++, j = i + 1, k = n -1;
    }
    vector<vector<int>> result(ans.size());
    int p = 0;
    for(const auto &vec : ans)
    {
        result[p] = vec;
    }
    return result;
}
int main()
{
    vector<int> ans= {-1,0,1,2,-1,-4};
    vector<vector<int>> result = threeSum(ans);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < 3 ; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}