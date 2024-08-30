#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// since diameter is calculated using edges and we can calculate height using the function height calculator
// Step - 1 : We will try to calculate height and also used a maximum height tracker 
// Step - 2 : 

int height(TreeNode *root, int &result)
{
    // base case
    if (root == nullptr)
        return 0;
    int leftHeight = height(root->left, result);
    int rightHeight = height(root->right, result);
    result = max(result, leftHeight + rightHeight);
    return max(leftHeight, rightHeight) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    // if root is null
    if (root == nullptr)
        return 0;
    int ans = INT_MIN;
    height(root, ans);
    return ans;
}

int main()
{

    return 0;
}