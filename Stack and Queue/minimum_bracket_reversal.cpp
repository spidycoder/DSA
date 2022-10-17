#include <iostream>
#include <string>
using namespace std;

#include<stack> 
int countBracketReversals(string input) {
	// Write your code here
    int count=0;
    if(input.size() % 2 != 0)
        return -1;

    stack<char> stk;
    for(int i = 0; i< input.size();i++){
        if(input[i] == '{')
            stk.push(input[i]);
        else if(input[i] == '}')
        {
            //removing the balanced parenthesis  
            if(!stk.empty() && stk.top() == '{')
                stk.pop();
            else if(stk.empty())
                stk.push(input[i]);
            else if(!stk.empty() && stk.top() != '{')
                stk.push(input[i]);    
        }
    }
    while(!stk.empty()){
    char s1=stk.top();
    stk.pop();
    char s2=stk.top();
    stk.pop();
    if(s1==s2){
        count++;
    }
    
        else
            count += 2;
    }
    return count;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}