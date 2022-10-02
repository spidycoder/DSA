#include <iostream>
using namespace std;

int lastIndex(int *arr, int size, int x)
{
    if (size == 0)
    {
        return -1;
    }
    int ans = lastIndex(arr + 1, size - 1, x);
    if (ans == -1)
    {
        if (arr[0] == x)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return ans + 1;
    }
}
int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {

        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout<<lastIndex(arr,size,k);
    delete []arr;
}