/*
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

*/
#include <bits/stdc++.h>
using namespace std;

bool checkAB(char input[])
{

    int len = strlen(input);

    if (len == 0)
    {
        return false;
    }

    // checkAB(input+1);

    if (input[0] != 'a')
    {
        return false;
    }
    else
    {
        if (input[1] == '\0')
        {
            return true;
        }
        else if (input[1] == 'a' && input[2] == '\0')
        {
            return true;
        }
        else if (input[1] == 'b' && input[2] == 'b' && input[3] == '\0')
        {
            return true;
        }
        else if (input[1] == 'b' && input[2] == 'b')
        {
            return checkAB(input + 3);
        }
    }
    // when all conditions are not satisfied then call recursion on input+1;
    return checkAB(input + 1);
}

int main()
{
    char input[100];
    bool ans;
    cin >> input;
    ans = checkAB(input);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}