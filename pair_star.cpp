/*
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
*/
#include <bits/stdc++.h>
using namespace std;

void pairStar(char input[])
{
    int n = strlen(input); //base case
    
    if (n == 0 || n == 1) {
        return;
        
    }
    //	pairStar(input + 1);
    if (input[0] == input[1]) {
        // shifting each element of string towards right to insert "*".
        for (int i = n; i > 0; i--) {
            input[i + 1] = input[i];
        }
        input[1] = '*';
        pairStar(input + 2);  //calling recursing for rest array as we have worked on first two positions

    }
    else {
        pairStar(input + 1);
    }
}


int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
    return 0;
}