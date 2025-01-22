#include <bits/stdc++.h>
using namespace std;

void dfsTraversal(int stRow, int stCol, int &color, vector<vector<int>> &image, vector<vector<int>> &visited)
{
    int n = image.size();
    int m = image[0].size();
    int startPixelVal = image[stRow][stCol];
    if (visited[stRow][stCol] == 0 && visited[stRow][stCol] != color)
    {
        visited[stRow][stCol] = 1;
        image[stRow][stCol] = color;
    }
    int delRow[] = {1, 0, -1, 0};
    int delCol[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nRow = stRow + delRow[i];
        int nCol = stCol + delCol[i];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == startPixelVal && visited[nRow][nCol] != color)
        {
            dfsTraversal(nRow, nCol, color, image, visited);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    dfsTraversal(sr,sc, color, image, visited);
    return image;
}

int main()
{

    return 0;
}
