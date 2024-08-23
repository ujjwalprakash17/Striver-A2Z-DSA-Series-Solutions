#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *insertAtEnd(Node *head, int x)
{
    Node *pt = new Node(x);
    // Code here
    if(head == nullptr) return head = pt; //if LL is empty
    Node *t = head;
    while(t->next != 0)
    t = t->next;
    t ->next  = pt;
    return head;
}

int main()
{

    return 0;
}