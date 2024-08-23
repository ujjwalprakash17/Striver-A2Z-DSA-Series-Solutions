#include <bits/stdc++.h>
using namespace std;

Node *constructLL(vector<int> &arr)
{
    // code here
    // will create the first head seperately
    Node *head, *last;
    head = new Node(arr[0]);
    last = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *t = new Node(arr[i]);
        last->next = t;
        last = t;
    }
    return head;
}

int main()
{

    return 0;
}