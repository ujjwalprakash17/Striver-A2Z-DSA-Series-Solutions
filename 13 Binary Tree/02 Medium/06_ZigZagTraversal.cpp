#include <bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == nullptr)
        return result;
    queue<TreeNode *> q;
    q.push(root);
    int flag = 0;
    while (!q.empty())
    {
        int levelSize = q.size();
        vector<int> temp;
        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *curr = q.front();
            temp.push_back(curr->val);
            q.pop();
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
        if (flag == 0)
        {
            result.push_back(temp);
            flag = 1;   
        }
        else
        {
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            flag = 0;
        }
    }
    return result;
}

int main()
{

    return 0;
}