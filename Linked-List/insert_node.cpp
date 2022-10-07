#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

Node* insertNode(Node *head,int i,int data){
	Node *newNode=new Node(data);
	//finding the position where we want to isert
	int count=0;
	Node *temp=head;
	//if i==0 the we need to add the node at the begning only and update the head
	if(i==0){
		newNode->next=head;
		head=newNode;
		return head;
	}
	while(temp!=NULL && count<i-1){
		temp=temp->next;
		count++;
	}
	//inserting the new node
	if(temp!=NULL){
	Node *a=temp->next;
	temp->next=newNode;
	newNode->next=a;
	}
	return head;
}

void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
}



int main(){
	Node *head=takeinput();
	print(head);
	int i,data;
	cin>>i>>data;
	head=insertNode(head,i,data);
	print(head);

    return 0;
}


