#include <iostream>

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

using namespace std;


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

//function to reverse linked-list
Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    //small calculation
    Node *smallAns=reverseLinkedListRec(head->next);
    //traversing along the linked-list reurned from the recursion
    Node *temp=smallAns;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //connecting head to last node of smallAns
    temp->next=head;
    //updating next of head
    head->next=NULL;
    return smallAns;
}
int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}