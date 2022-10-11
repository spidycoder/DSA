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

Node *midPoint(Node *head)
{
    // Write your code here
    // Base case
    if (head == NULL)
    {
        return head;
    }
    int size = 0;
    Node *temp = head;
    // finding the size of LL
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    int l = (size - 1) / 2;
    int count = 0;
    temp = head;
    // finding the required position of LL
    while (count < l && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return temp;
}
Node* mergeTwoSortedLinkedLists(Node *head1, Node *head2) {
    //Base Case
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    //Creating two Nodes
    Node*fh=NULL;
    Node*ft=NULL;
    //assigning the pointer by comparing
    if(head1->data<head2->data){
        fh=head1;
        ft=head1;
        head1=head1->next;
    }
	else{
        fh=head2;
    	ft=head2;
        head2=head2->next;
    }
      //traversing through the list.  
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            ft->next=head1;
            ft=head1;
            head1=head1->next;
        }
        else{
            ft->next=head2;
            ft=head2;
            head2=head2->next;
        }
    }
    //if anyone of head1 or head2 becomes NULL
    if(head1==NULL){
        ft->next=head2;
    }
    if(head2==NULL){
        ft->next=head1;
    }
    return fh;
   
    
}


// Function to sort list using merge
Node *mergeSort(Node *head)
{
    // Write your code here
    if (head == NULL)
    {
        return head;
    }
    Node *mid = midPoint(head);
    Node *Head = head;
    Node *Head2= mid->next;
    int count = 0;
    while (count < mid->data && Head != NULL)
    {
        Head = Head->next;
        count++;
    }
    if (mid == Head)
    {

        mid = mid->next;
    }
   Node *temp1= mergeSort(Head);
   Node *temp2 =  mergeSort(Head2);
   head->next=mergeTwoSortedLinkedLists(temp1,temp1);
   return head;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        head = mergeSort(head);
        print(head);
    }
    
    return 0;
}