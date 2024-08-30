#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return (node);
}

// void create_tree(node *root0, vector<int> &vec)
// {
//     //will take q for level order traversal
//     root0 = newNode(vec[0]);
//     queue<node *>q;
//     q.push(root0); 
//     int i = 1;
//     while(!q.empty() && i < vec.size())
//     {
//         node *curr = q.front();
//         q.pop();
//         //create left node and right node
//         node *leftNode = newNode(vec[i++]);
//         node *rightNode = newNode(vec[i++]);
//         curr->left = leftNode;
//         q.push(curr->left); 
//         curr->right = rightNode;
//         q.push(curr->right); 
//     }

// }

void create_tree(node*& root0, vector<int>& vec) {
    if (vec.empty()) {
        root0 = nullptr; // Handle empty vector
        return;
    }

    root0 = newNode(vec[0]);
    queue<node*> q;
    q.push(root0);
    int i = 1;

    while (!q.empty() && i < vec.size()) {
        node* curr = q.front();
        q.pop();

        // Create left node
        if (i < vec.size()) {
            curr->left = newNode(vec[i++]);
            q.push(curr->left);
        }

        // Create right node
        if (i < vec.size()) {
            curr->right = newNode(vec[i++]);
            q.push(curr->right);
        }
    }
}


int main()
{

    return 0;
}