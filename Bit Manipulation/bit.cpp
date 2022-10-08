#include <bits/stdc++.h>
using namespace std;
// function to print binary of a number

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
    printBinary(9);
    // code to check whether bit of a number is set or not.
    int a = 9;
    int pos = 3;
    if (a & (1 << pos) != 0)
    {
        cout << "Set Bit\n";
    }
    else
    {
        cout << "Not set\n";
    }
    // how to set ith bit of a numer
    printBinary(a | (1 << 1));
    // how to unset ith bit of a number
    printBinary(a & (~(1 << 3)));
    // how to toggle a bit of a number
    printBinary(a ^ (1 << 2));
    printBinary(a ^ (1 << 3));
    // How to count the set Bit of a number
    int cnt = 0;
    while (a)
    {
        cnt += a & 1;
        a >>= 1;
    }
    cout << cnt << endl;
    // OR
    // In built-function to print set bit of a number
    cout <<__builtin_popcount(a);
    //for large integers,builtin functiion is __builtin_popcountll();
    cout<<__builtin_popcountll((1LL<<35)-1);
    return 0;
}