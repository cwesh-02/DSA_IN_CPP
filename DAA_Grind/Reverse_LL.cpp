#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

int main()
{
    int n ;
    cout<<"Enter n";
    cin>>n;

    Node* head=NULL;
    Node* curr=head;

    for(int i =0;i<n;i++)
    {
        int temp;
        cout<<"Enter Node "<< i+1;
        cin>>temp;

        if(!head)
        {
            head = new Node(temp);
            curr = head;
        }

        else
        {
        curr->next = new Node(temp);
        curr=curr->next;
        }
    }

    Node* h = head;
    Node* prev = NULL;

    while(h)
    {
        Node* tmp = h->next;
        h->next = prev;
        prev = h;
        h = tmp;
    }

    while(prev)
    {
        cout<<prev->data<<"->";
        prev = prev -> next;
    }

    cout<<"NULL";

    return 0;
}
