#include <bits/stdc++.h>
using namespace std;

void solution(int ind, string &digits, vector<string> &mapping, string temp, vector<string> &result)
{
    // base case
    if (ind >= digits.length())
    {
        result.push_back(temp);
        return;
    }
    // run a loop
    for (char ch : mapping[digits[ind] - '0'])
    {
        solution(ind + 1, digits, mapping, temp + ch, result);
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    solution(0, digits, mapping, "", result);
    return result;
}

int main()
{

    return 0;
}