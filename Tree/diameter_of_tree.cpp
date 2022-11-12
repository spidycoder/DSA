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
int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    
    return max(height(root->left),height(root->right))+1;
}
//diameter of tree
int diameter(BinaryTreeNode<int>* root){
    int d=0;
    if(root==NULL){
        return 0;
    }
    //here 1 is added for root node
    int option1 = height(root->left)+height(root->right)+1;
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1,max(option2,option3));
}
//another best approach for finding diameter of tree
pair<int,int> heightDiameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);
    int left_height = leftAns.first;
    int left_diameter = leftAns.second;
    int right_height = rightAns.first;
    int right_diameter = rightAns.second;
    int height = 1 + max(left_height,right_height);
    int diameter = max(left_height+right_height,max(left_diameter,right_diameter));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}
int main() 
{
BinaryTreeNode<int>* root = takeInputLevelWise();
PrintTree(root);
cout<<endl;
pair<int,int> p = heightDiameter(root);
cout<<"Height: "<<p.first<<endl;
cout<<"Diameter: "<<p.second<<endl;
delete root;
    
return 0;
}