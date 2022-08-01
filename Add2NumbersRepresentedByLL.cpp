//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       first = reverse(first);
     second = reverse(second);
     int carry = 0;
     Node* list = new Node(0);
     Node* newHead = list;
     while(first && second){
         int sum = first->data + second->data + carry;
         list->next = new Node(sum%10);
         carry = sum/10;
         list = list->next;
         first = first->next;
         second = second->next;
     }
     while(first){
          int sum = first->data  + carry;
         list->next = new Node(sum%10);
         carry = sum/10;
         list = list->next;
         first = first->next;
     }
     while(second){
          int sum = second->data + carry;
         list->next = new Node(sum%10);
         carry = sum/10;
         list = list->next;
         second = second->next;
     }
     
     if(carry > 0){
         list->next = new Node(carry);
     }
    newHead = reverse(newHead->next);
     return newHead;
    }
    
    Node* reverse(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
