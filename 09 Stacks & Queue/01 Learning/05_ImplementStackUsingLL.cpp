#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        if(top){
            StackNode *temp = new StackNode(x);
            temp->next = top;
            top = temp;
        }else{
            top = new StackNode(x);
        }
    }

    int pop() {
        // code here
        if(top == NULL) return -1;
        int res = top->data;
        StackNode *temp = top;
        top = top->next;
        delete(temp);
        return res;
    }

    MyStack() { top = NULL; }
};


//{ Driver Code Starts.

int main() {

}
