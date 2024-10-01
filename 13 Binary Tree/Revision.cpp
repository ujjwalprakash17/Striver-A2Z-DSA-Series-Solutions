#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
void inOrder (TreeNode *root, vector<int> &result)
{
    //base case 
    if(root == nullptr) return ;
    //left root right
    inOrder(root->left, result);
    result.push_back(root->data);
    inOrder(root->right, result);

}
void preOrder (TreeNode *root, vector<int> &result)
{
    //base case 
    //root left right
    if(root == nullptr) return ;
    result.push_back(root->data);
    preOrder(root->left, result);
    preOrder(root->right, result);

}
void postOrder (TreeNode *root, vector<int> &result)
{
    //base case 
    //right root left 
    if(root == nullptr) return ;
    postOrder(root->left, result);
    postOrder(root->right, result);
    result.push_back(root->data);

}
vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans1;
    inOrder(root, ans1);
    vector<int> ans2;
    preOrder(root, ans2);
    vector<int> ans3;
    postOrder(root, ans3);
    return {ans1, ans2, ans3};
}

int main()
{


    return 0;
}