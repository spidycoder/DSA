#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

#include<bits/stdc++.h>
int i=0;
int countNodes(BinaryTreeNode<int>* root){
	if(root==NULL)return 0;
	
	
	return 1+countNodes(root->left)+countNodes(root->right);
}

void preOrder(BinaryTreeNode<int>* root,int arr[]){
	if(root==NULL)return;
	
	arr[i++]=root->data;
	
	
	preOrder(root->left,arr);
	preOrder(root->right,arr);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
   
	int n = countNodes(root);
	int arr[n];
	preOrder(root,arr);
	sort(arr,arr+n);
	int i=0,j=n-1;
	while(i<j){
		if(arr[i]+arr[j]==sum){
			cout<<arr[i]<<" "<<arr[j]<<endl;
			i++;
		j--;
		}
		else if((arr[i]+arr[j])>sum){
			j--;
		}
		else{
			i++;
		}
		
	}

}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}