#include <iostream>
using namespace std;

#include <queue>
#include <stack>
stack<int> extra;
// reversing queue using stack
void reverseQueue(queue<int> &input)
{
    // Write your code here
    int j;
    // putting all interger values in stack in LIFO order
    while (!input.empty())
    {
        int k = input.front();
        extra.push(k);
        input.pop();
    }
    // just print the stack elements,we will get our required result
    while (!extra.empty())
    {
        cout << extra.top() << " ";
        extra.pop();
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++)
        {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}