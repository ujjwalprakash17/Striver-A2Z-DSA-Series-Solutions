#include <bits/stdc++.h>
using namespace std;
//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head)
{
    
}

ListNode *create_list(ListNode *&root, vector<int> &arr)
{
    //
    root = new ListNode(arr[0]);
    ListNode *last = root;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        last->next = temp;
        last = temp;
    }
    return root;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    ListNode *root = nullptr;
    root = create_list(root, arr);
    ListNode *p = root;
    while (p != 0)
    {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}