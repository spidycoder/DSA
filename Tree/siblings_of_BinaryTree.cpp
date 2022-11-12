/*
For a given Binary Tree of type integer, print all the nodes without any siblings.
Two nodes are said to be siblings if they are present at the same level, and their parents are same.

Examples: 

Input : 
       1
      /  \
     2    3
    / \  / \
   4   5 6  7
First node is 4 and Second node is 6.
Output : No, they are not siblings.

Input :
         1
        /  \
       5    6
      /    /  \
     7     3   4
First node is 3 and Second node is 4
Output : Yes
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

void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
   //base case
    if(root==NULL) return ;
    //if left-sub-tree is NULL then print right
    if(root->left==NULL && root->right!=NULL)  
        cout<<root->right->data<<" ";
    //if right-sub-tree is NULLL then print left
    if(root->left!=NULL && root->right==NULL ) 
        cout<<root->left->data<<" ";
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printNodesWithoutSibling(root);
}
