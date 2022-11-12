#include <bits/stdc++.h>
using namespace std;

// TreeNode class
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;
    // creating constructor
    TreeNode(T data)
    {
        this->data = data;
    }
};

// function to print Tree
void PrintTree(TreeNode<int> *root)
{
    // One Corner Case
    if (root == NULL)
    {
        return;
    }
    // printing the root node
    cout << root->data << ":";
    // printing the children corresponding to that class
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ";
    }
    cout << endl;
    // printing the children nodes
    for (int i = 0; i < root->children.size(); i++)
    {
        PrintTree(root->children[i]);
    }
}

// function to take input of Tree
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter the Data: " << endl;
    cin >> rootData;
    // creating a root node with rootData
    TreeNode<int> *root = new TreeNode(rootData);
    int n;
    cout << "Enter the number of children: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        // connecting to final node
        root->children.push_back(child);
    }
    return root;
}

// another simpler approach to take input
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter the RootData: " << endl;
    cin >> rootData;
    // creating a root node with rootData
    TreeNode<int> *root = new TreeNode(rootData);
    //creating a queue
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    //loop till queue is not empty
    while(pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter the num of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        //loop for taking input of children data
        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            //creating a node for child data
            TreeNode<int>* child = new TreeNode<int>(childData);
            //connecting with the root node
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }return root;
}
int main()
{
    /*
    TreeNode<int> *root = new TreeNode(1);
    // creating two children with data 2 and 3
    TreeNode<int> *node1 = new TreeNode(2);
    TreeNode<int> *node2 = new TreeNode(3);
    // connecting root node and children node
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    TreeNode<int> *root = takeInput();
    PrintTree(root);

    return 0;
}

