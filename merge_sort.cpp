#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void merge(int *arr, int l, int mid, int u)
{
    int k = u + 1 - l;
    int output[k];
    int i = l, j = mid + 1, m = 0;
    while (i <= mid && j <= u)
    {
        if (arr[i] < arr[j])
        {
            output[m] = arr[i];
            m++;
            i++;
        }
        else
        {
            output[m] = arr[j];
            m++;
            j++;
        }
    }
    while (i <= mid)
    {
        output[m] = arr[i];
        m++;
        i++;
    }
    while (j <= u)
    {
        output[m] = arr[j];
        m++;
        j++;
    }
    for (int i = 0; i < m; i++)
    {
        arr[l] = output[i];
        l++;
    }
}

void mergeSortHelper(int *input, int l, int u)
{
    if (l >= u)
    {
        return;
    }

    int mid = (l + u) / 2;

    mergeSortHelper(input, l, mid);
    mergeSortHelper(input, mid + 1, u);

    merge(input, l, mid, u);
}

void mergeSort(int input[], int size)
{
    mergeSortHelper(input, 0, size - 1);
}

int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}