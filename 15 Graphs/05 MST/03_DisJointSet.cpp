#include <bits/stdc++.h>
using namespace std;

// Disjoint Set
class DisjointSet
{
    vector<int> size, parent;

public:
    // Constructor
    DisjointSet(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 1; i < n + 1; i++)
            parent[i] = i;
    }
    // we have find parent method
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    // Union by size
    void unionSets(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot)
            return; // because in this case they both belong to same parent
        if (size[xRoot] < size[yRoot])
        {
            parent[xRoot] = yRoot;
            size[yRoot] += size[xRoot];
        }
        else
        {
            parent[yRoot] = xRoot;
            size[xRoot] += yRoot;
        }
    }
    // For debugging: Print parent array
    void printParents()
    {
        for (int i = 0; i < parent.size(); i++)
        {
            cout << "Node " << i << " -> Parent: " << parent[i] << ", Size: " << size[i] << endl;
        }
    }
};

int main()
{
    DisjointSet ds(7); // Create 7 disjoint sets

    ds.unionSets(0, 1);
    ds.unionSets(1, 2);
    ds.unionSets(3, 4);
    ds.unionSets(5, 6);
    ds.unionSets(4, 5);
    ds.unionSets(2, 6); // Merge all

    cout << "Parent array after unions:\n";
    ds.printParents();

    cout << "\nFind representative of 6: " << ds.find(6) << endl;
    cout << "Find representative of 3: " << ds.find(3) << endl;

    return 0;
}

// <--------------------Striver's Code ------------------------------------->

// //Steps to find Union
// //find ultimate parent of u and v
// //find rank of u and v
// //connect the smaller rank with higher rank
// //if rank is same then connect anyone with anyone

// //T.C = 4 alpha ~ 1

// class DisJointSet {
//     vector<int> parent, rank;
//     public :
//     DisJointSet(int n){
//         parent.resize(n+1);
//         rank.resize(n+1, 0);
//         for(int i = 1; i <= n ; i++) parent[i] = i;
//     }
//     int findUltimateParent(int node){
//         if(node == parent[node])
//         return node;
//         return parent[node] = findUltimateParent(parent[node]); // we are finding ultimate parent with path compression
//     }

//     void unionByRank(int u, int v){
//         int ultParentOfU = findUltimateParent(u);
//         int ultParentOfV = findUltimateParent(v);
//         if(ultParentOfU == ultParentOfV) return ; // this means they both are connected component
//         if(rank[ultParentOfU] < rank[ultParentOfV])
//         {
//             parent[ultParentOfU] = ultParentOfV; // this means we are setting the u's parent to v's ultimate parent
//         }else if(rank[ultParentOfU] > rank[ultParentOfV]) {
//             parent[ultParentOfV] = ultParentOfU;
//         }else{ // when rank of both ultparent of U and V both are same then we could set any one to other and increase the rank in which we joined them
//             parent[ultParentOfU] = ultParentOfV;
//             ultParentOfV++;
//         }
//     }
// };
