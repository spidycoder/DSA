#include <bits/stdc++.h>
using namespace std;

int stringToNumber(char input[])
{
    if (strlen(input) == 1)
    {
        return input[0] - '0';
    }
    int ans = stringToNumber(input + 1);
    int b = input[0] - '0';
    return b * (pow(10, strlen(input) - 1)) + ans;
}

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input);
}