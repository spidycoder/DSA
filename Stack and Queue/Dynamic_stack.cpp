#include <bits/stdc++.h>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    // constructor
    StackUsingArray()
    {
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }
    // size() function
    int size()
    {
        return nextIndex;
    }
    // isEmpty() function
    bool isEmpty()
    {
        /*
        if(nextIndex==0){
            return true;
        }
        else{
            return false;
        }
        */
        // shorter way to write above codes
        return nextIndex == 0;
    }
    // push() function
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            int *newdata = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            capacity = 2 * capacity;
            data = newdata;
        }

        data[nextIndex] = element;
        nextIndex++;
    }
    // pop()
    int pop()
    {
        if (nextIndex == 0)
        {
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // top()
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};
int main()
{
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}