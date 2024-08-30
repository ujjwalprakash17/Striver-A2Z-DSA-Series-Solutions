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

vector<int> postorderTraversal(TreeNode* root) {
    if (root == nullptr) return {}; // Check if root is nullptr

    stack<TreeNode*> st1;
    st1.push(root);
    stack<TreeNode*> st2;
    while (!st1.empty()) {
        TreeNode* curr = st1.top();
        st1.pop();
        st2.push(curr);
        // push right
        if (curr->right != nullptr)
            st1.push(curr->right);
        // push left
        if (curr->left != nullptr)
            st1.push(curr->left);
    }
    vector<int> result;
    while (!st2.empty()) {
        result.push_back(st2.top()->val);
        st2.pop();
    }
    return result;
}

int main()
{

    return 0;
}