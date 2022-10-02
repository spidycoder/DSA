#include <bits/stdc++.h>
using namespace std;

//My approach
void removeX(char input[])
{
    if (strlen(input) == 0)
    {
        return;
    }
    //calling recursion for rest part of string
    if (input[0] != 'x')
    {

        removeX(input + 1);
    }
    //work done by us
    else
    {
        int n=strlen(input);

        for (int i = 0; i < n; i++)
        {
            input[i ] = input[i+1];
        }
         
         removeX(input);  //calling recursion again so that any 'x' which is present between the characters of string is removed and we are passing the same string because firslty,we have shortern our string

    }
}

// void removeX(char input[]) {
//     // Write your code here
//     if(input[0]=='\0')
//         return;
//     if(input[0]!='x')
//     {
//         removeX(input+1);
//     }
//     else{
//         int i=1;
//         for(;input[i]!='\0';i++)
//         {
//             input[i-1]=input[i];
//         }
//         input[i-1]=input[i];
//         removeX(input);
//     }
// }

int main()
{
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}