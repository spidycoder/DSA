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

Node *deleteNode(Node *head, int pos)
{
    Node *temp = head;
    if (head == NULL)
    {
        return NULL;
    }
    if (pos == 0)
    {
        head = temp->next;
        return head;
    }
    int count = 0;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL && temp->next != NULL)
    {

        Node *current = temp->next;
        Node *PrevPtr = current->next;
        temp->next = PrevPtr;
        delete current;
    }
    return head;
}

//function to delelte node recursively
Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    Node *temp = head;
    //Base Case
    if(head==NULL){
        return head;
    }
    //small calculation
    if(pos == 0){
       head = temp->next;
       return head;
        
    }
    //recursive call
    head->next = deleteNodeRec(head->next,pos-1);
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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int pos;
        cin >> pos;
        head = deleteNode(head, pos);
        print(head);
    }

    return 0;
}
