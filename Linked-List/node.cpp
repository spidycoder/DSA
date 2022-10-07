#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
    }
};

//Print function to display  the node data
void print(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    /*

    // Creating objects statically
    Node n1(1);
    // storing the address of head
    Node *head = &n1;
    Node n2(2);
    // connceting two nodes
    n1.next = &n2;
    //printing n1 and n2 with the help of head
    //for n1
    cout<<head->data<<endl;
    //for n2;
    cout<<(head->next)->data<<endl;

    //Dynamically
    Node *n3=new Node(3);
    //storing the address of first node
    Node *head=n3;
    Node *n4=new Node(4);
    //connecting two nodes
    n3->next=n4;

    */
   //creting a linked-list of 5 nodes
     Node n1(1);
    Node *head = &n1;
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    n5.next=NULL;
    print(head);
    return 0;
}