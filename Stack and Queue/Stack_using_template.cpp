#include <bits/stdc++.h>
using namespace std;

template <typename T>
class StackUsingArray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    // constructor
    StackUsingArray()
    {
        data = new T[4];
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
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            T *newdata = new T[2 * capacity];
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
    T pop()
    {
        if (nextIndex == 0)
        {
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // top()
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};
int main()
{
    //interger type stack
    StackUsingArray<int> s;
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
    //character type stack
    StackUsingArray<char> s1;
    //here 100,101,102,103 are considered as ASCII value
    s1.push(100);
    s1.push(101);
    s1.push(102);
    s1.push(103);
    s1.push(104);
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.isEmpty()<<endl;
    return 0;
}