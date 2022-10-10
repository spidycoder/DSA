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

int findNode(Node *head, int n)
{
    if(head==NULL)
         return -1;
    
    int count = 0;
    Node *temp = head;
    Node* temp2=head;
    int size=0;
    while(temp2!=NULL)
    {
        size++;
        temp2=temp2->next;
    }

    /*Here temp!=NULL will be checked first and after that temp->data!=n will be checked
    because in && both condtion must be true and if we write temp->data!=n then loop will 
    go to last point it becomes false and then it will not check for temp!=NULL
    */
   
    while ( temp!=NULL && temp->data != n )
    {
        temp = temp->next;
        count++;
    }
    
    if(count>=size)
        return -1;
    
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int val;
        cin >> val;
        cout << findNode(head, val) << endl;
    }
}