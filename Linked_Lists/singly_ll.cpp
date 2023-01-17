#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int key)
    {
        data = key;
        next = NULL;
    }
};

Node *insertBegin(Node *head,int x){
    Node *temp = new Node(x);
    temp->next=head;
    return temp;
    
}

int search(Node * head, int x){
    int pos=1;
    Node *curr=head;
    while(curr!=NULL){
        if(curr->data==x)
            return pos;
        else{
            pos++;
            curr=curr->next;
        }
    }
    return -1;
}

Node *insertEnd(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL)return temp;
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return head;
    
}

Node *delHead(Node *head){
    if(head==NULL)return NULL;
    else{
        Node *temp=head->next;
        delete(head);
        return temp;
    }
}


Node *delTail(Node *head){
    if(head==NULL)return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node *curr=head;
    while(curr->next->next!=NULL)
        curr=curr->next;
    delete (curr->next);
    curr->next=NULL;
    return head;
}


Node* removeDuplicates(Node* head)
{
	Node *temp = head, *prev = head;

	while (temp != NULL) {
		if (temp->data != prev->data) {
			prev->next = temp;
			prev = temp;
		}
		temp = temp->next;
	}
	if (prev != temp)
		prev->next = NULL;
	return head;
}