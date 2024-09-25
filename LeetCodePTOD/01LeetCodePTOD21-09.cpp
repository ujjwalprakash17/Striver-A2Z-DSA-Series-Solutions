//To do problem 
#include <bits/stdc++.h>
using namespace std;

void solution(int val, int n, vector<int> &temp, int &limit)
{
    // base case
    if (val > n)
        return;
    temp.push_back(val);
    val *= 10;
    solution(val, n, temp, limit);
    val /= 10;
    for (int i = val + 1; i <= limit; i++)
        temp.push_back(i);
    limit = val - 1;
}

vector<int> lexicalOrder(int n)
{
    vector<int> ans;
    solution(1, n, ans, n);
    return ans;
}

int main()
{
    int n = 34;
    vector<int> result = lexicalOrder(n);
    for(int i= 0 ; i < result. size(); i++)
    cout << result[i] << " ";

    return 0;
}