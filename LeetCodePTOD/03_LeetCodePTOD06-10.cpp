#include <bits/stdc++.h>
using namespace std;

bool areSentencesSimilar(string sentence1, string sentence2)
{
    int len1 = sentence1.size();
    int len2 = sentence2.size();
    int flag = 0;
    int i = 0, j = 0;
    int cnt = 0;
    while(i < len1 && j < len2)
    {
        if(cnt > 1) return false;
        if(flag == 0 && sentence1[i] != sentence2[j] ){
            cnt++;
            flag = 1;
        }
        

    }
    return true;
}

int main()
{

    return 0;
}