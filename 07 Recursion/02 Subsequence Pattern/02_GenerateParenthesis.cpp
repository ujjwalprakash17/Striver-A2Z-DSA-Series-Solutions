#include <bits/stdc++.h>
using namespace std;

void solution(string temp, int left, int right, vector<string> &result)
{
    if (left == 0 && right == 0)
    {
        result.push_back(temp);
        return;
    }
    if (left > 0)
        solution(temp + '(', left - 1, right, result);
    if (right > left)
        solution(temp + ')', left, right - 1, result);
}
vector<string> generateParenthesis(int n)
{
    vector<string> result;
    // string temp = ""
    solution("", n, n, result);
    return result;
}

int main()
{

    return 0;
}