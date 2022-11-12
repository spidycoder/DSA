/*
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present
*/

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};



TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

//findig the maximum value
TreeNode<int>* firstLargestNode(TreeNode<int>* root){
    if(root==NULL){
        return NULL; 
    }
    TreeNode<int>* max_value = root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* ans = firstLargestNode(root->children[i]);
        if(ans->data>max_value->data)max_value=ans;
    }
    return max_value;
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root){
    //finding the maximum value
    TreeNode<int>* ans = firstLargestNode(root);
    //after finding the max value,initialising it with -infinity to remove from tree and now the largest in tree will
    //be second largest in whole tree.
    ans->data= INT_MIN;
    return firstLargestNode(root);
   
    
}

//another approach
TreeNode<int>* solve(TreeNode<int>* root,TreeNode<int>* &largest,TreeNode<int>* &secondLargest) {
    
    
    if(largest == NULL || root->data > largest->data){
        secondLargest = largest;
        largest = root;
    }else if(secondLargest == NULL && root->data != largest->data){
            secondLargest = root;
    }

    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* childs = solve(root->children[i],largest,secondLargest);
    }
    
    return secondLargest;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    //initialising the largest and second largest by NULL
    TreeNode<int>* largest  = NULL;
    TreeNode<int>* secondLargest = NULL;
    return solve(root,largest,secondLargest);
}


int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}   