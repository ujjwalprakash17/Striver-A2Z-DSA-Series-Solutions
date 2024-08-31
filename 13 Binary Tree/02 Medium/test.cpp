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
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
    {
        return;
    }
    result.push_back(root->data);
    if (root->left != nullptr)
    {
        visitLeft(root->left, result);
    }
    else
    {
        visitLeft(root->right, result);
    }
}

// step 2: visit all the leaf nodes function
void visitLeaf(Node *root, vector<int> &result)
{
    if (root == nullptr) return;
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
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
        return;
    st.push(root->data);
    if (root->right != nullptr)
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
    vector<int> result;
    if (root == nullptr) return result;
    
    // Add root data if it's not a leaf node
    if (root->left != nullptr || root->right != nullptr)
        result.push_back(root->data);
    
    // step 1 : visit the left most part of the root
    visitLeft(root->left, result);
    
    // step 2 : visit all the leaf nodes
    visitLeaf(root, result);
    
    // step 3 : visit right side but in reverse order
    stack<int> st;
    visitRight(root->right, st);
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