#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

//program to find isBST
#include<bits/stdc++.h>
int maximum(BinaryTreeNode<int>* root){
	if(root==nullptr)return INT_MIN;
	
	return max(root->data,max(maximum(root->left),maximum(root->right)));
	
}
int minimum(BinaryTreeNode<int> *root) {
  if (root == nullptr)
    return INT_MAX;
 
  return min(root->data,min(minimum(root->left),minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root==nullptr)return true;
    int left_max = maximum(root->left);
	int right_min = minimum(root->right);
	bool output = (root->data>left_max) && (root->data<=right_min) && (isBST(root->left)) && (isBST(root->right));
	return output;
	
	
}

//another approach
class IsBSTReturn{
  public:
    bool IsBST;
    int minimum;
    int maximum;
};
IsBSTReturn IsBST2(BinaryTreeNode<int>* root){
    if(root==nullptr){
        //crating an object of class
        IsBSTReturn output;
        output.IsBST=true;
        output.minimum= INT_MAX;
        output.maximum=INT_MIN;
        return output;
    }
    IsBSTReturn leftOutput = IsBST2(root->left);
    IsBSTReturn rightOutput = IsBST2(root->right);
    IsBSTReturn output;
    int minimum = min(root->data,min(leftOutput.minimum,rightOutput.minimum));
    int maximum = max(root->data,max(leftOutput.maximum,rightOutput.maximum));
    bool IsBSTFinal = (root->data>leftOutput.maximum) && (root->data<=rightOutput.minimum) && leftOutput.IsBST && rightOutput.IsBST;
    output.IsBST=IsBSTFinal;
    output.minimum=minimum;
    output.maximum=maximum;
    return output;
    
}
//another short approach
bool IsBST(BinaryTreeNode<int>* root,int min=INT_MIN,int max=INT_MAX){
    if(root==nullptr)return true;
    if(root->data<min || root->data>max)return false;
    //checking for left and right
    bool isLeftOk = IsBST(root->left,min,root->data-1);
    bool isRightOk = IsBST(root->right,root->data,max);
    return isLeftOk && isRightOk;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}