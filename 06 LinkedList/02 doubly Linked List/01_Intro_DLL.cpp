#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

Node *constructDLL(vector<int> &arr)
{
    // code here
    // step 1 : Will create the first Node seperately
    Node *head = new Node(arr[0]);
    Node *previous = head, *last = head;
    for(int i = 1 ; i < arr.size();  i++)
    {
        Node *t = new Node(arr[i]);
        
    }
}

int main()
{

    return 0;
}