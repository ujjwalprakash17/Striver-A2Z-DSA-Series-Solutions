#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> visited(n, vector<int> (m, 0));
    vector<vector<int>> distance(n, vector<int>(m));
    queue<pair<pair<int, int>, int>> q;
    // {{row, col}, val};
    //put the initial elements in the queue that are 0s
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m ; j++){
            if(mat[i][j] == 0){
                q.push({{i, j}, 0}); //push into queue and 
                visited[i][j] = 1; // mark it visited 
            }
        }
    }
    while(!q.empty()){
        int currRow = q.front().first.first;
        int currCol = q.front().first.second;
        int currVal = q.front().second;
        distance[currRow][currCol] = currVal;
        q.pop();
        int delRow[] = {-1, 0, 1 , 0};
        int delCol[] = {0, 1 , 0, -1};
        for(int i = 0; i < 4 ; i++){
            int nRow = currRow + delRow[i];
            int nCol = currCol + delCol[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && mat[nRow][nCol] != 0){
                q.push({{nRow, nCol}, currVal + 1});
                visited[nRow][nCol] = 1;
            }
        }
    }
    return distance;
}


int main()
{

    return 0;
}