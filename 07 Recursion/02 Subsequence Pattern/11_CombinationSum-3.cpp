#include <bits/stdc++.h>
using namespace std;

void solution(int ind, int k, int n, vector<int> temp, set<vector<int>> &tempResult)
{
    if(ind > 9) return;
    if(k == 0){
        if(n == 0){
            tempResult.insert(temp);
        }
        return;
    }
    if(ind > n){
        return;
    }
    //pick state
    temp.push_back(ind+1);
    solution(ind+1, k-1, n-(ind+1), temp, tempResult);
    temp.pop_back();
    solution(ind+1, k, n, temp, tempResult);

}

vector<vector<int>> combinationSum3(int k, int n)
{
    set<vector<int>> tempResult;
    vector<int> temp;
    // function call here
    solution(0, k, n, temp, tempResult);
    vector<vector<int>> result(tempResult.begin(), tempResult.end());
    return result;
}

int main()
{
    vector<vector<int>> result = combinationSum3(3, 7);
    for(auto ele : result)
    {
        for(int it : ele)
        cout << it << " ";
        cout << endl;
    }

    return 0;
}