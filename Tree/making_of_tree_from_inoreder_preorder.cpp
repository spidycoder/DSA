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

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
    //Base Case
	if (inS > inE) {
		return NULL;
	}
    //finding the root data
	int rootData = pre[preS];
    //finding root in Inorder
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}
    //finding the necessary variables
	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS;
	int rPreS = lPreE + 1;
	int rPreE = preE;
	int rInS = rootIndex + 1;
	int rInE = inE;
	BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
    //making left-sub-tree
	root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}

BinaryTreeNode<int>* buildTree(int* in,int* pre,int size){
    return buildTreeHelper(in,pre,0,size-1,0,size-1);
}
int main() 
{
int in[]={4,2,5,1,8,6,9,3,7};
int pre[]={1,2,4,5,3,6,8,9,7};
BinaryTreeNode<int>* root = buildTree(in,pre,9);
PrintTree(root);
delete root;
    
return 0;
}