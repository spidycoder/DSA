/*
Given a Binary tree, find the largest BST subtree. 
That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST
*/

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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
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

#include <bits/stdc++.h>
bool IsBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX) {
  if (root == nullptr)
    return true;
  if (root->data < min || root->data > max)
    return false;
  // checking for left and right
  bool isLeftOk = IsBST(root->left, min, root->data - 1);
  bool isRightOk = IsBST(root->right, root->data, max);
  return isLeftOk && isRightOk;
}

int height(BinaryTreeNode<int> *root){
	if(root==NULL)return 0;
	return  max(height(root->left),height(root->right))+1;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL)return 0;
  if(IsBST(root)){
    return height(root);
  }
  return max(largestBSTSubtree(root->left),largestBSTSubtree(root->right));



}

//use another approach by making  a class in which we will find min,max,IsBST,height in same
//class

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}