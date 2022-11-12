#include<iostream>
using namespace std;
class BST
{
    BinaryTreeNode<int> *root;

    bool Search(int data, BinaryTreeNode<int> *node)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        else if (data < node->data)
        {
            return SearchData(data, node->left);
        }
        else if (node->data < data)
        {
            return SearchData(data, node->right);
        }
        return false;
    }

    BinaryTreeNode<int> *InsertHelper(int data, BinaryTreeNode<int> *root)
    {
        if (root == nullptr)
        {
            BinaryTreeNode<int> *NewRoot = new BinaryTreeNode<int>(data);
            return NewRoot;
        }
        if (data > root->data)
            root - right = InsertHelper(data, root->right);
        if (data < root->data)
            root->left = InsertHelper(data, root->left);
        return root;
    }

    BinaryTreeNode<int> *deleteHelper(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return NULL;
        if (root->data < data)
            root->right = deleteHelper(data, root->right);
        if (root->data > data)
            root->left = deleteHelper(data, root->left);
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return nullptr;
            }
            else if (root->left == NULL)
            {
                // if we call delte root first then right part will be deleted so first we will store right part in some temp variable
                BinaryTreeNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                BinaryTreeNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            // if root's left and right is not null
            else
            {
                // replacing root with right's min data
                BinaryTreeNode<int> *minNode = root->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                root->data = rightMin;
                root->right = deleteHelper(data, root->right);
                return root;
            }
        }
        return root;
    }

    void PrintTree(BinaryTreeNode<int> *root)
    {
        // base case
        if (root == NULL)
        {
            return;
        }
        cout << root->data << ":";
        if (root->left != NULL)
        {
            cout << "L " << root->left->data;
        }
        if (root->right != NULL)
        {
            cout << " R " << root->right->data;
        }
        cout << endl;
        PrintTree(root->left);
        PrintTree(root->right);
    }

public:
    // constructor
    BST()
    {
        root = nullptr;
    }
    // destructor
    ~BST()
    {
        delete root;
    }
    // Important functions
    bool SearchData(int data, BInaryTreeNode<int> *root)
    {

        return Search(data, root);
    }

    void insert(int data)
    {
        root = InsertHelper(data, root);
    }
    void delete (int data)
    {
        root = deleteHelper(data, root);
    }
    void printTree(){
        printTree(root);
    }
};