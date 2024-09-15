#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *p = list1, *q = list2;
    ListNode *result = nullptr, *last= nullptr;
    while (p != nullptr && q != nullptr)
    {
        ListNode *temp = nullptr;
        if(p->val  <= q->val)
        {
            temp = p;
            p = p->next;
        }
        else{
            temp = q;
            q = q->next;
        }
        if(result == nullptr)
        {
            result = temp;
            last = temp;
        }
        else{
            last->next = temp;
            last = temp;
        }
    }
    while( p != nullptr)
    {
        if(last == nullptr)
        {
            result = p;
            break;
        }
        last->next = p;
        last = p;
        p = p->next;
    }
    while (q != nullptr)
    {
        if (last == nullptr)
        {
            result = q;
            break;
        }
        last->next = q;
        last = q;
        q = q->next;
    }

    return result;
}

int main()
{


    return 0;
}