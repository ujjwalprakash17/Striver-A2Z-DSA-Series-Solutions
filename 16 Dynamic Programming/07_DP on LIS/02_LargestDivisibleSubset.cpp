#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void buildPath(int ind, vector<int> &nums, vector<int> &parent,
                   vector<int> &ans)
    {
        if (parent[ind] == ind)
        {
            ans.push_back(nums[ind]);
            return;
        }
        buildPath(parent[ind], nums, parent, ans);
        ans.push_back(nums[ind]);
    }

public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return {};

        // Sort the array first - this is crucial!
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);  // dp[i] = length of longest subset ending at i
        vector<int> parent(n); // parent[i] = previous element in the subset

        // Initialize parent array
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        int maxLength = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // Since array is sorted, nums[i] >= nums[j]
                // So we only need to check if nums[i] % nums[j] == 0
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    maxLength = max(maxLength, dp[i]);
                }
            }
        }

        // Find the index with maximum length
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxLength)
            {
                buildPath(i, nums, parent, ans);
                break;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}