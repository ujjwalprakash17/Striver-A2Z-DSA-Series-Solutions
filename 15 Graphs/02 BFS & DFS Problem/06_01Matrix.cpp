#include <bits/stdc++.h>
using namespace std;

// my doubt :
//  case 1 :
// if I pushed in the queue 0 first then with processing each of 0's and updating each of the ones distance
//  but what will happen in case of below test case?
//  {[0,0,0],[0,1,0],[1,1,1]} what will happen to the 1 in the middle

// case 2:
// if I pushed in the queue 1 first then still in this case what will happend to the middle 1 in the 3rd row

// sol : since we are updating distance which is ansMat, so case 1 will work, and if we used case 2 then it will be more complex since we have to spread the values of distance outwards

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> ansMat(n, vector<int>(m, -1));
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({0, {i, j}});
                ansMat[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        int currDist = q.front().first;
        int currRow = q.front().second.first;
        int currCol = q.front().second.second;
        q.pop();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nRow = currRow + delRow[i];
            int nCol = currCol + delCol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && ansMat[nRow][nCol] == -1)
            {
                ansMat[nRow][nCol] = currDist + 1;
                q.push({currDist + 1, {nRow, nCol}});
            }
        }
    }
    return ansMat;
}


int main()
{

    return 0;
}