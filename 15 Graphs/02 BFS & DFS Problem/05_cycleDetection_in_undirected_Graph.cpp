#include <bits/stdc++.h>
using namespace std;

// Approach :
//  1. take each of the string into set (so that it makes searching in wordlist easier)
//  2. try solving using bfs
//  3. insert the beginword into queue
//  4. start the loop till the queue is not empty
//  5. take each front word out and try to find out which word exists in set
//  6. if found the word take the word out from the queue and also from set data structure
//  7. that is all

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    set<string> st;
    for (string i : wordList)
    {
        st.insert(i);
    }
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    while (!q.empty())
    {
        string currWord = q.front().first;
        int currLvl = q.front().second;
        // try finding for each word in set
        for(int i = 0; i < st.size() ; i++){
            for(int j = 0 ; j < currWord.size();  j++){
                for(int k = 1; k < 26; k++){
                    currWord[i] = 
                }
            }
        }
    }
}

int main()
{

    return 0;
}