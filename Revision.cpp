#include <bits/stdc++.h>
using namespace std;

string shiftingLetters(string s, vector<vector<int>> &shifts)
{
    int n = s.size();
    vector<int> freq(n + 2, 0);
    for (auto it : shifts)
    {
        int start = it[0];
        int end = it[1];
        int direc = it[2];
        if (direc == 1)
        {
            freq[start]++;
            freq[end + 1]--;
        }
        else
        {
            freq[start]--;
            freq[end + 1]++;
        }
    }
    int shift = 0;
    for (int i = 0; i < n; ++i)
    {
        shift += freq[i];
        shift %= 26;                                 // Because there are 26 letters in the alphabet
        s[i] = (s[i] - 'a' + shift + 26) % 26 + 'a'; // Ensuring the result is within 'a' to 'z' }
    }
    return s;
}

int main()
{
    string s = "dztz";
    vector<vector<int>> shifts = {{0, 0, 0}, {1, 1, 1}};
    s = shiftingLetters(s, shifts);
    cout << s << "\n";
    // int val = (124 % 97) % 26;
    // cout << val << "\n";
    return 0;
}#include <bits/stdc++.h>
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