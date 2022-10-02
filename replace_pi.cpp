#include <bits/stdc++.h>
using namespace std;

void replacePi(char input[])
{
    if (strlen(input) == 0 || strlen(input) == 1)
        return;

    replacePi(input + 1);
    //small calculation by us.
    if (input[0] == 'p' && input[1] == 'i')
    {

        // loop to shift the integers by 4 places

        for (int i = strlen(input) - 1; i >= 2; i--)
        {
            input[i + 2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
    return 0;
}