#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
// step - 1 : visit all the left part of the tree
void visitLeft(Node *root, vector<int> &result)
{
    // base case : if both of the left and right is null then return
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        return;
    }
    result.push_back(root->data);

    // case 2 : if left is null then, go for right
    if (root->left != nullptr)
    {
        visitLeft(root->left, result);
    }
    else
    {
        visitLeft(root->right, result);
    }
}
// step 2: visit all the leaf nodes funtion
void visitLeaf(Node *root, vector<int> &result)
{

    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        result.push_back(root->data);
        return;
    }
    visitLeaf(root->left, result);
    visitLeaf(root->right, result);
}
// step - 3 : visit right side but in reverse order
void visitRight(Node *root, stack<int> &st)
{
    if (root == nullptr)
        return;
    // base case : agar left ya right dono null hai toh return kr do
    if (root->left == nullptr && root->right == nullptr)
        return;
    // if right ya left me se koi ek hai toh
    st.push(root->data);
    // check for right first if not then go for left
    if (root->right != nullptr )
    {
        visitRight(root->right, st);
    }
    else
    {
        visitRight(root->left, st);
    }
}
vector<int> boundary(Node *root)
{
    // Your code here
    vector<int> result;
    if(root == nullptr) return result;
    if (root->left != nullptr || root->right != nullptr)
    result.push_back(root->data);
    // step 1 : visit the left most part of the root
    visitLeft(root->left, result);
    // step 2 : visit all the leaf nodes
    visitLeaf(root, result);
    // step 3 : visit right side but in reverse order
    stack<int> st;
    visitRight(root->right, st);
    // copy the value of stack into the
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}

int main()
{

    return 0;
}