#include <bits/stdc++.h>
using namespace std;

// The idea behind Kruskals Algorithm is :
// Step 1:  We will start with each node individually
// Step 2: We will choose those edges first which has minimum edges weight (greedily)
// Step 3: while picking edges we have to be sure that they don't form a cycle (we will do this using disjoint set)
//  that's it
class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x]; // this will mandatorily have parent[x] not x,
        // because in the middle of recursive calls we will be returning the parent of x not directly x, which will lead to an incorrect result
    }
    int unionBySize(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot)
            return 0;
        else if (size[xRoot] < size[yRoot])
        {
            parent[xRoot] = yRoot;
            size[yRoot] += size[xRoot];
        }
        else
        {
            parent[xRoot] = yRoot;
            size[xRoot] += size[yRoot];
        }
        return 1;
    }
};

int kruskalsMST(int V, vector<vector<int>> &edges)
{
    // code here
    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b)
         {
             return a[2] < b[2]; // this is written to sorted in desceding order
         });
    // now we will traverse each of the edges
    int mstSum = 0;
    DisjointSet ds(V);
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (ds.unionBySize(u, v))
            mstSum += wt;
    }
    return mstSum;
}

int main()
{

    return 0;
}