#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node* prev;
};/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev
   }
*/
Node* SortedInsert(Node *head,int data)
{
    if (head == NULL) {
        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;
        return temp;
    }
    else {
        Node *p = head;
        Node *cur = NULL;
        while (p->data <= data) {
            cur = p;
            p = p->next;
            if (p == NULL) {
                Node *temp = new Node();
                temp->data = data;
                temp->next = NULL;
                cur->next = temp;
                temp->prev = cur;
                return head;
            }
        }
        if (cur == NULL) {
            Node *temp = new Node();
            temp->data = data;
            temp->next = head;
            head->prev = temp;
            return temp;
        }
        Node *temp = new Node();
        temp->data = data;
        cur->next = temp;
        temp->next = p;
        temp->prev = cur;
        p->prev = temp;
        return head;
    }
}

void Print(Node *head) {
	if(head == NULL) return;
	while(head->next != NULL){ cout<<head->data<<" "; head = head->next;}
	cout<<head->data<<" ";
	while(head->prev != NULL) { cout<<head->data<<" "; head = head->prev; }
	cout<<head->data<<"\n";
}

int main()
{
	int t; cin>>t;
	Node *head = NULL;
	while(t--) {
	   int n; cin>>n;
           head = NULL;
	   for(int i = 0;i<n;i++) {
		   int x; cin>>x;
		   head = SortedInsert(head,x);
	       Print(head);
	   }
	}
}