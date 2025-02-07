#include <bits/stdc++.h>
using namespace std;

//Steps to find Union
//find ultimate parent of u and v
//find rank of u and v
//connect the smaller rank with higher rank
//if rank is same then connect anyone with anyone

//T.C = 4 alpha ~ 1

class DisJointSet {
    vector<int> parent, rank;
    public :
    DisJointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i = 1; i <= n ; i++) parent[i] = i;
    }
    int findUltimateParent(int node){
        if(node == parent[node])
        return node;
        return parent[node] = findUltimateParent(parent[node]); // we are finding ultimate parent with path compression
    }

    void unionByRank(int u, int v){
        int ultParentOfU = findUltimateParent(u);
        int ultParentOfV = findUltimateParent(v);
        if(ultParentOfU == ultParentOfV) return ; // this means they both are connected component
        if(rank[ultParentOfU] < rank[ultParentOfV])
        {
            parent[ultParentOfU] = ultParentOfV; // this means we are setting the u's parent to v's ultimate parent
        }else if(rank[ultParentOfU] > rank[ultParentOfV]) {
            parent[ultParentOfV] = ultParentOfU;
        }else{ // when rank of both ultparent of U and V both are same then we could set any one to other and increase the rank in which we joined them
            parent[ultParentOfU] = ultParentOfV;
            ultParentOfV++;
        }
    }
};

int main() {
    
    return 0;
}