#include <bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int>& arr) {
    int mod = 1e9+7;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            vector<int> temp;
            for (int j = i; j < arr.size(); j++) {
                temp.push_back(arr[i]);
                int tempSum = *min_element(temp.begin(), temp.end()) % mod; 
                sum += tempSum;
            }
        }
        return sum % mod;
    }

int main()
{
    vector<int> sample = {3,1,2,4};
    return 0;
}