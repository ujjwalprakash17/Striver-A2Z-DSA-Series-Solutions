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

// we will try to return -1 if at any point the difference between left subtree and right subtree is greater than 1
//once we got a -1 either in left part or right part then we must return -1 everytime.
int height(TreeNode *root)
{
    //
    if (root == nullptr)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight == -1 || rightHeight == -1)
        return -1;
    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    return max(leftHeight, rightHeight) + 1;
}
bool isBalanced(TreeNode *root)
{
    int val = height(root);
    if (val == -1)
        return false;
    return true;
}

int main()
{

    return 0;
}