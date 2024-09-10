#include <bits/stdc++.h>
using namespace std;

void solution(int ind, int n , vector<int> &arr, vector<int> &temp)
{
    if(ind == n)
    {
        if(temp.size() == 0)
        {
            cout << "{}" << endl;
            return ;
        }
        for(int i = 0; i < temp.size() ; i++)
        cout << temp[i] << " ";
        cout << endl;
        return; 
    }
    // pick condition
    temp.push_back(arr[ind]);
    solution(ind + 1, n , arr,temp );
    // not pick condition
    temp.pop_back();
    solution(ind + 1, n , arr,temp );
}

int coinChange(vector<int> &coins, int amount)
{
    // sort the coin in reverse
    
}

int main()
{
    // vector<int> sample = {186,419,83,408};
    vector<int> sample = {1,2,3,4};
    // int amount = 6249;
    // cout << coinChange(sample, amount) << endl;
    vector<int> temp;
    solution(0, 4, sample, temp);
    return 0;

}