/*
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on.
 This means odd levels should get printed from left to right and even level right to left.
*/

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
//function to print zig-zag traversal
#include <bits/stdc++.h>
void zigZagOrder(BinaryTreeNode<int> *root)
{
    // Write your code here

    if (root == NULL)
    {
        return;
    }
    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            BinaryTreeNode<int> *front = s1.top();
            cout << front->data << " ";
            s1.pop();
            if (front->left != NULL)
            {
                s2.push(front->left);
            }

            if (front->right != NULL)
            {
                s2.push(front->right);
            }
        }
        cout << endl;

        while (!s2.empty())
        {
            BinaryTreeNode<int> *front = s2.top();
            cout << front->data << " ";
            s2.pop();
            if (front->right != NULL)
            {
                s1.push(front->right);
            }

            if (front->left != NULL)
            {
                s1.push(front->left);
            }
        }

        cout << endl;
    }
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    zigZagOrder(root);
}