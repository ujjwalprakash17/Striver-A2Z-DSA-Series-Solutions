#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode *root)
{
    //edge case if root is empty 
    vector<int> result;
    if(root == nullptr)
    return result;
    // if not empty
    stack<TreeNode *> st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();
        result.push_back(curr->val);
        if(curr->right != nullptr)
        st.push(curr->right);
        if(curr->left != nullptr)
        st.push(curr->left);
    }
    return result;
}

int main()
{

    return 0;
}