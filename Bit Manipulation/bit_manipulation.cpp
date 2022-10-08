#include <bits/stdc++.h>
using namespace std;

void printBinary(int n)
{
    for (int i = 10; i >= 0; --i)
    {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

int main()
{
    // some Bit Manipulation Tricks
    for (int i = 0; i < 8; i++)
    {
        printBinary(i);
        // checking odd and even
        //(i&1) and (n%2!=0) gives same result but (i&1) is faster than (n%2!=0)
        if (i & 1)
        {
            cout << "Odd\n";
        }
        else
        {
            cout << "Even\n";
        }
    }
    // Multiplication and division of a number by 2 using Bit Manipulation
    int n = 5;
    // for division by 2,we left shift the number by 1
    cout << (n >> 1) << endl;
    // for multiplication,we right shift number by 1.
    cout << (n << 1) << endl;

    // converting lowercase to uppercase and vice-versa.
    for (char c = 'A'; c <= 'E'; c++)
    {
        cout << c << endl;
        printBinary(c);
    }
    for (char c = 'a'; c <= 'e'; c++)
    {
        cout << c << endl;
        printBinary(c);
    }
    // converting A into a.
    cout << char('A' | (1 << 5)) << endl;
    // OR
    cout << char('A' | ' ') << endl;
    // converting a into A
    cout << char('a' & (~(1 << 5))) << endl;
    // OR
    cout << char('a' & '_') << endl;

    // clearing the least significant bit till i.
    printBinary(59);
    int a = 59;
    int i = 4;
    int b = (a & (~((1 << (i + 1)) - 1)));
    printBinary(b);

    // clearing the most significant bit till i.
    printBinary(59);
    int c = 59;
    int j = 3;
    int d = c & (((1 << (j + 1)) - 1));
    printBinary(d);

    // trik to check whether a number of power 2 or not
    int k = 16;
    if (k & (k - 1) != 0)
    {
        cout << "Not power of 2" << endl;
    }
    else
    {
        cout << "Power of 2" << endl;
    }
    return 0;
}