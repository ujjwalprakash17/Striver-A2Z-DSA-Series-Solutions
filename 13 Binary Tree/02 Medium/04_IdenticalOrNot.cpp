#include <bits/stdc++.h>
using namespace std;

// User function Template for C++


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool isSameTree(TreeNode *p, TreeNode *q)
{
    // 4 different conditions
    if (p == nullptr && q == nullptr)
        return true;
    else if (p != nullptr && q == nullptr)
        return false;
    else if (p == nullptr && q != nullptr)
        return false;
    else
    {
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        bool curr = p->val == q->val;
        if (left && right && curr)
            return true;
        return false;
    }
    return true;
}
int main()
{

    return 0;
}