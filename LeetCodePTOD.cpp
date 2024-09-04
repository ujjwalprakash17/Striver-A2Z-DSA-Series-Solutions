#include <bits/stdc++.h>
using namespace std;

string changeDirection(string &currentDirection, int val)
{
    unordered_map<string, int> mp;
    // unordered_map<int, string> mp;
    mp["West"] = 0;
    mp["North"] = 1;
    mp["East"] = 2;
    mp["South"] = 3;
    string ans = "";
    int i = mp[currentDirection];
    if (val == -1)
    {
        if (i == 3)
            return "West";
        for(const auto& pair : mp)
        {
            if(pair.second == i + 1)
            return pair.first ;
        }
    }
    else if (val == -2)
    {
        if (i == 0)
        {
            return "South";
        }
        for(const auto &pair : mp)
        {
            if(pair.second == i -1)
            return pair.first;
        }
    }
    return ans;
}

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
{
    string currentDirection = "North";
    int x= 0, y = 0;
    for (int i = 0; i < commands.size(); i++)
    {
        if (commands[i] == -1 || commands[i] == -2)
        {
            currentDirection = changeDirection(currentDirection, commands[i]);
        }
        else
        {
            if (currentDirection == "North")
            y += commands[i];
            else if(currentDirection == "South")
            y-= commands[i];
            else if(currentDirection == "East")
            x += commands[i];
            else if(currentDirection == "West")
            x-= commands[i];
        }
    }
}

int main()
{
    unordered_map<string, int> mp;

    return 0;
}