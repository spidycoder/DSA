#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// stack class using LL
class Stack
{
    // Define the data members
    Node *head;
    int size;

public:
    Stack()
    {
        // Implement the Constructor
        head = NULL;
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function
        return size == 0;
    }

    void push(int element)
    {
        // Implement the push() function

        Node *newNode = new Node(element);

        newNode->next = head;
        head = newNode;
        size++;
    }
    // Important
    int pop()
    {
        // Implement the pop() function
        // Base case
        if (size == 0)
        {
            return -1;
        }
        // storing the data which is to be deleted so that it can be returned
        int ans = head->data;
        // storing the address of head in a variable so that when head is deleted then,rest list is preserve
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    int top()
    {
        // Implement the top() function
        if (size == 0)
        {
            return -1;
        }
        return head->data;
    }
};
int main()
{
    return 0;
}