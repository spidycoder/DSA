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
// function to print level wise
void printLevelWise(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *curr = q.front();
        q.pop();
        cout << curr->data << ":";
        // after pushing the data,check for left and right of curr variable and push it's left and right in queue
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);

        // first print left side if it is null or not null
        if (root->left == NULL)
        {
            cout << "L:-1"
                 << ",";
        }
        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << ",";
        }

        // after printing left side completely,print right side
        if (root->right != NULL)
        {
            cout << "R:" << root->right->data;
        }
        if (root->right == NULL)
        {
            cout << "R:-1";
        }

        cout << endl;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printLevelWise(root);
}