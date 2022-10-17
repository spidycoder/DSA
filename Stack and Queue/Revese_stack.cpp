#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra)
{
    // Write your code here
    // creating a variable which will store values of extra stack
    int j;
    // traversing the input stack
    while (!input.empty())
    {
        // making input stack empty and putting all values of input stack in reverse order in extra stack
        int i = input.top();
        input.pop();
        extra.push(i);
    }
    // traversing the extra stack
    while (!extra.empty())
    {
        // making extra stack empty and putting all the values of extra stack in reverse order in input stack
        j = extra.top();
        extra.pop();
        input.push(j);
        int k = input.top();
        cout << k << " ";
        input.pop();
    }
}

int main()
{
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++)
    {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
}