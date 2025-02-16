#include <bits/stdc++.h>
using namespace std;

bool dfsTraversal(int stNode, int colorOfNode, vector<int> &color, vector<vector<int>>& graph){
    color[stNode] = colorOfNode;
    for(int neighbour : graph[stNode]){
        // if node not visited
        if(color[neighbour] == -1){
            int neighbourColor = colorOfNode == 1 ? 0 : 1;
            if(dfsTraversal(neighbour, neighbourColor, color, graph) == false)
            return false;
        }
        else{
            if(color[neighbour] == colorOfNode){
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int noOfNodes = graph.size();
    vector<int> color(noOfNodes, -1);
    for(int i = 0;i  < noOfNodes; i++)
    {
        if(color[i] == -1)
        {
            if(dfsTraversal(i, 0, color, graph) == false)
            return false;
        }
    }
    return true;
}

int main() {
    
    return 0;
}