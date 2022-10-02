/*Given a string S, remove consecutive duplicates from it recursively*/
#include <bits/stdc++.h>
using namespace std;

void removeConsecutiveDuplicates(char s[])
{
    if (s[0] == '\0')
    {
        return;
    }
    removeConsecutiveDuplicates(s + 1);
    if (s[0] == s[1])
    {
        int i = 1;
        for (i = 1; s[i] != '\0'; i++)
        {
            s[i - 1] = s[i];
        }
        s[i - 1] = s[i];
        return;
    }
    else
    {
        return;
    }
}

int main()
{
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}