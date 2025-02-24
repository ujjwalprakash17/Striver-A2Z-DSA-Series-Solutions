#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    // will apply bfs
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    wordSet.erase(beginWord);
    // The case in which we don't have endWord with us
    if (wordSet.find(endWord) == wordSet.end()) return 0;
    while(!q.empty())
    {
        string currString = q.front().first;
        int currLvl = q.front().second;
        q.pop();
        // traverse its neighbours 
        for(int i = 0; i < currString.length(); i++)
        {
            string temp = currString;
            for(char c = 'a' ; c <= 'z' ; c++)
            {
                temp[i] = c;
                //check if it is the same string as currString 
                if(temp == currString) continue;
                if(temp == endWord) return currLvl + 1;
                if(wordSet.find(temp) != wordSet.end())
                {
                    q.push({temp, currLvl + 1});
                    wordSet.erase(temp);
                }
            }
        }
    }
    return 0;
}


vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
}


int main()
{
    return 0;

    

 
