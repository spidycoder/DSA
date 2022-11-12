#include<bits/stdc++.h>
using namespace std;

//creating a BinaryTreeNode class

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    //creating a constructor
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    //creating a destructor to delete the tree after it's use
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }

};

//print function to print the tree
void PrintTree(BinaryTreeNode<int>* root){
    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L "<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<" R "<<root->right->data;
    }
    cout<<endl;
    PrintTree(root->left);
    PrintTree(root->right);
}

//taking input of binary tree
BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Data "<<endl;
    cin>>rootData;
    //when user enters data as -1,that means we have to stop taking input
    if(rootData == -1){
        return NULL;
    }
    //creating a root with rootData
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    //taking input for left-sub-tree
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    //connectiong leftChild and rightChild with root's left and right
    root->left=leftChild;
    root->right=rightChild;
    return root;
}

//taking input level wise
BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter Data "<<endl;
    cin>>rootData;
    //when user enters data as -1,that means we have to stop taking input
    if(rootData == -1){
        return NULL;
    }
    //creating a root with rootData
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    //creating a queue
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        //taking input for left-binary-tree
        cout<<"Enter left childe of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!=-1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        //taking input for right-binary-tree
        cout<<"Enter right childe of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
int main() 
{
BinaryTreeNode<int>* root = takeInputLevelWise();
PrintTree(root);
delete root;
    
return 0;
}