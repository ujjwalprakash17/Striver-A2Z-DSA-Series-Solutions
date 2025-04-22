#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    // we know the distance between the cells which are 0 from itself is 0
    //so push the blocks which are initially 0
    queue<pair<pair<int, int>, int>> q;
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(mat[i][j] == 0){
                q.push({{i, j}, 0});
            }
        }
    }

    while(!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++)
        {
            int nRow = delRow[i] + row;
            int nCol = delCol[i] + col;
            if(nRow >=0 && nRow < n && nCol >= 0 && nCol < m && )
        }
    }

}

int main()
{

    return 0;
}