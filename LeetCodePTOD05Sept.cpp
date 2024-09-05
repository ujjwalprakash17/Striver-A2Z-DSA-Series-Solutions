#include <bits/stdc++.h>
using namespace std;

    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
{
    vector<int> ans;
    long long currSum = accumulate(rolls.begin(), rolls.end(), 0);
    int m = rolls.size();
    long long totalSum = mean * (n + m);
    long long remSum = totalSum - currSum;
    double maxVal = (double)remSum / (double)n;
    if(maxVal < 1 ||  maxVal > 6) return {};


    for(int i = 0; i < n ; i++) 
    {
        ans.push_back((int)maxVal);
        remSum -= (int)maxVal;
    }
    int i = 0;
    while(remSum > 0){
        ans[i] += 1;
        remSum -= 1;
    }
    return ans;
}
int main()
{
    vector<int> sample = {4,5,6,2,3,6,5,4,6,4,5,1,6,3,1,4,5,5,3,2,3,5,3,2,1,5,4,3,5,1,5};
    int mean = 3;
    int n = 4;
    vector<int> result = missingRolls(sample, mean, n);
    for(int i = 0; i < result.size() ; i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}