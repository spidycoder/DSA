#include <iostream>
using namespace std;

int helper(int input[], int start, int end, int element)
{
    if (start >= end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (input[mid] == element)
    {
        return mid;
    }
    else if (input[mid] > element)
    {
        return helper(input, start, mid - 1, element);
    }
    else
    {
        return helper(input, mid + 1, end, element);
    }
}

int binarySearch(int input[], int size, int element)
{
    return helper(input, 0, size - 1, element);
}




int main()
{
    int input[100000], length, element, ans;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
        ;
    }

    cin >> element;
    ans = binarySearch(input, length, element);
    cout << ans << endl;
}
