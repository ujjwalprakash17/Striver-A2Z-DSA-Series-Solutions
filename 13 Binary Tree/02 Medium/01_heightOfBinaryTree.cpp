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
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
int maxDepth(TreeNode *root)
{
    // base case
    if (root == nullptr)
        return 0;
    int leftSide = maxDepth(root->left);
    int rightSide = maxDepth(root->right);
    return max(leftSide, rightSide) + 1;
}

int main()
{

    return 0;
}