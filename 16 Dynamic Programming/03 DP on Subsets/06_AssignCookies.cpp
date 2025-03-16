#include <bits/stdc++.h>
using namespace std;

int solution(int ind, string temp, vector<int>& digits)
{
    //out of bound
    if(ind == 0)
    {
        if(temp.length() == 3)
        {
            int val = 0;
            for(int i = 0 ; i < 3 ; i++)
            {
                val = val * 10 + (temp[i] - '0');
            }
            return (val >= 100);
        }
    }
    char ch = '0' + digits[ind];
    int notPick = solution(ind -  1, temp , digits);
    int pick = solution(ind - 1, temp + ch, digits);
    return pick + notPick;
}

int totalNumbers(vector<int>& digits) {
    int n = digits.size();  
    return solution(n-1, "", digits);
}
int main() {
    
    return 0;
}