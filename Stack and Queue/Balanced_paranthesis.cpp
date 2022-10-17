#include <iostream>
#include <string>
using namespace std;

#include <stack>
stack<char> s;
bool isBalanced(string expression)
{
    // Write your code here
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            s.push(expression[i]);
        }
        if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
             if(s.size()==0){
                return false;
            }
            if (s.top() == '(' || s.top() == '{' || s.top() == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if(s.size()==0){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}