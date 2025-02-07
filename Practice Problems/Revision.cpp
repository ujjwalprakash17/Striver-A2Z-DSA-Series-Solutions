#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> ans;
    if(root == nullptr) return ans;
    while(!q.empty())
    {
        int levelSize = q.size();
        vector<int> temp;
        for(int i = 0; i < levelSize ; i++){
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            temp.push_back(curr->val);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{

    return 0;
}