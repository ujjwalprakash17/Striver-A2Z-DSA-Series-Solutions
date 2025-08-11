#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination)
{
    // code here
    if(source == destination) return 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {source.first, source.second}});
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
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && dist[nRow][nCol] > currDist + 1)
            {
                if (nRow == destination.first && nCol == destination.second)
                    return currDist + 1;
                dist[nRow][nCol] = currDist + 1;
                q.push({currDist + 1, {nRow, nCol}});
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// // Disjoint Set
// class DisjointSet
// {
//     vector<int> size, parent;

// public:
//     //Constructor
//     DisjointSet(int n)
//     {
//         parent.resize(n + 1, 0);
//         size.resize(n + 1, 1);
//         for (int i = 1; i < n + 1; i++)
//             parent[i] = i;
//     }
//     // we have find parent method
//     int find(int x)
//     {
//         if(parent[x] != x)
//         {
//             parent[x] = find(parent[x]);
//         }
//         return parent[x];
//     }
//     //Union by size
//     void unionSets(int x, int y)
//     {
//         int xRoot = find(x);
//         int yRoot = find(y);
//         if(xRoot == yRoot) return ; //because in this case they both belong to same parent
//         if(size[xRoot] < size[yRoot]){
//             parent[xRoot] = yRoot;
//             size[yRoot] += size[xRoot];
//         }else{
//             parent[yRoot] = xRoot;
//             size[xRoot] += yRoot;
//         }
//     }
//     // For debugging: Print parent array
//     void printParents() {
//         for (int i = 0; i < parent.size(); i++) {
//             cout << "Node " << i << " -> Parent: " << parent[i] << ", Size: " << size[i] << endl;
//         }
//     }
// };

// int main() {
//     DisjointSet ds(7);  // Create 7 disjoint sets

//     ds.unionSets(0, 1);
//     ds.unionSets(1, 2);
//     ds.unionSets(3, 4);
//     ds.unionSets(5, 6);
//     ds.unionSets(4, 5);
//     ds.unionSets(2, 6); // Merge all

//     cout << "Parent array after unions:\n";
//     ds.printParents();

//     cout << "\nFind representative of 6: " << ds.find(6) << endl;
//     cout << "Find representative of 3: " << ds.find(3) << endl;

//     return 0;
// }