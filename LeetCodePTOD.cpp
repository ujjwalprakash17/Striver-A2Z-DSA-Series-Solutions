#include <bits/stdc++.h>
using namespace std;

int countConsistentStrings(string allowed, vector<string> &words)
{
    vector<int> hash(26, 0);
    for (int i = 0; i < allowed.size(); i++)
    {
        hash[allowed[i] - 'a']++;
    }
    int cnt = 0;
    for (int i = 0; i < words.size(); i++)
    {
        int flag = 0;
        for (int j = 0; j < words[i].size(); j++)
        {
            if (hash[words[i][j] - 'a'] == 0)
            {
                flag = 1;
            }
        }
        if(flag == 0){
            cnt++;
            flag = 0;
        }
    }
    return cnt;
}

int main()
{

    return 0;
}