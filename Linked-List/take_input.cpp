#include<bits/stdc++.h>
using namespace std;

class Node {
	public :
	int data;
	Node *next;

	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};

// Node* takeInput() {
// 	int data;
// 	cin >> data;
// 	Node *head = NULL;
// 	while(data != -1) {
// 		Node *newNode = new Node(data);
// 		if(head == NULL) {
// 			head = newNode;
// 		}
// 		else {
// 			Node *temp = head;
// 			while(temp -> next != NULL) {
// 				temp = temp -> next;
// 			}
// 			temp -> next = newNode;
// 		}

// 		cin >> data;
// 	}
// 	return head;
// }

//better approach

Node* takeInput(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        
        }
        else{
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
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
    Node *head=takeInput();
    print(head);

    return 0;
}