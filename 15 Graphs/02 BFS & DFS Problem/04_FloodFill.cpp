#include <bits/stdc++.h>
using namespace std;

//working code 
void dfsTraversal(int row, int col, int originalVal, int color, vector<vector<int>> &image, vector<vector<int>> &visited) {
    visited[row][col] = color; // Mark the cell with the new color
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, 1, 0, -1};
    int n = image.size();
    int m = image[0].size();
    for(int i = 0; i < 4 ; i++) {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];
        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && visited[nRow][nCol] != color && image[nRow][nCol] == originalVal) {
            dfsTraversal(nRow, nCol, originalVal, color, image, visited);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> visited = image; // Initialize visited with the original image
    int originalValue = image[sr][sc];
    if (originalValue != color) { // Check to avoid unnecessary operations
        dfsTraversal(sr, sc, originalValue, color, image, visited);
    }
    return visited;
}


















//Not working code 
void dfsTraversal(int row, int col, int originalVal, int color, vector<vector<int>> &image, vector<vector<int>> &visited)
{
    if(visited[row][col] == -1)
    visited[row][col] = color;
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, 1 , 0, -1};
    int n = image.size();
    int m = image[0].size();
    for(int i = 0; i < 4 ; i++)
    {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];
        if(nRow >= 0 && nRow < n && nCol >= 0  && nCol < m  && visited[nRow][nCol] == -1 && image[nRow][nCol] == originalVal)
        {
            dfsTraversal(nRow, nCol, originalVal, color, image, visited);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> visited(n, vector<int> (m, -1));
    if(sr < n && sc < m)
    visited[sr][sc] = color;
    int originalValue = image[sr][sc];
    dfsTraversal(sr, sc, originalValue, color, image, visited);
    return visited;
}

int main()
{

    return 0;
}