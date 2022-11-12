/*
Given a binary tree, write code to create a separate linked list for each level.
 You need to return the array which contains head of each level linked list.
*/

#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

#include<bits/stdc++.h>

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<Node<int>*> ans;
    if(root == NULL) {
        return ans;
    }
    queue<BinaryTreeNode<int>* > q;
    q.push(root);
    q.push(NULL);
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    while(!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
		//checking if front is null or nort
        if(front == NULL) {
			//if front is null,the add it to ans
            ans.push_back(head);
            head = tail = NULL;
	//if queue size is 0 then we will brek but we can't return because,ifwe return then we would not be able to convet the BT to LL
            if(q.size() == 0) {
                break;
            }
			
			
            q.push(NULL);
        }
        else {
            Node<int>* newNode = new Node<int>(front->data);
        	if(head == NULL) {
        	    head = tail = newNode;
        	}
        	else {
        	    tail->next = newNode;
        	    tail = tail->next;
        	}
        	if(front->left) q.push(front->left);
        	if(front->right) q.push(front->right);
        }
    }
    return ans;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}