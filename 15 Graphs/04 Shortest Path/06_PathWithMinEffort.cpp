#include <bits/stdc++.h>
using namespace std;



int minimumEffortPath(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> efforts(n, vector<int> (m, 1e9));
    efforts[0][0] = 0;
    set<pair<int, pair<int, int>>> setDS;
    setDS.insert({0, {0 , 0}}); 
    while(!setDS.empty())
    {
        auto currEle = setDS.begin();
        int currEffort = currEle->first;
        int currRow = currEle->second.first;
        int currCol = currEle->second.second;
        setDS.erase(currEle);
        if(currRow == n-1 && currCol == m -1) return currEffort;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++)
        {
            int nRow = currRow + delRow[i];
            int nCol = currCol + delCol[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m)
            {
                int newEffort = max(currEffort , abs(heights[nRow][nCol] - heights[currRow][currCol]));
                if(newEffort < efforts[nRow][nCol])
                {
                    if(efforts[nRow][nCol] != 1e9){
                        setDS.erase({efforts[nRow][nCol], {nRow, nCol}});
                    }
                    setDS.insert({newEffort, {nRow, nCol}});
                    efforts[nRow][nCol] = newEffort;
                }
            }
        }
    }
    return -1;

}

int main()
{

    return 0;
}