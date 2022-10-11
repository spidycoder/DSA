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

Node *midPoint(Node *head)
{
    // Write your code here
    //Base case
    if(head == NULL ){
        return head;
    }
    int size=0;
    Node *temp = head;
    //finding the size of LL
    while(temp != NULL){
        size++;
        temp = temp->next;
        
    }
    int l = (size-1)/2;
    int count=0;
    temp = head;
    //finding the required position of LL
    while(count<l  &&  temp != NULL){
        temp = temp->next;
        count++;
    }
    
    return temp;
}


//another approach
Node *midPoint(Node *head)
{
    // Write your code here
    if(head==NULL)
    {
        return NULL;
    }
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        
    } 
    return slow;
}
    

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}