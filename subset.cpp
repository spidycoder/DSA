#include <bits/stdc++.h>
using namespace std;

int subset(int input[], int n, int output[][20]) {
    //base case.always consider -ve case for size for better practice.
     if (n <= 0)
  {
    output[0][0] = 0;
    return 1;
  }
  //recursion call.
  int ans = subset(input + 1, n-1, output);
  //here no_of_columns denotes length of the  subset.
  int number_of_columns=0;
  //iterating over the ouput array of subset generated from recursion call.
  for (int i = 0; i < ans; i++)
  {
    //initializing the no_of_columns with first column of output subset array returned from recursion call
    number_of_columns = output[i][0];
    //making copy of ouput array and incrementing the size of each subset array generated from recursion call.
    output[i + ans][0] = 1 + number_of_columns;
    //adding the first element of input array at second column of each row of subset array generated from recursion call
    output[i + ans][1] = input[0];
    //iterating over the output subarray from first column to shift each element towards right.
    for (int j = 1; j <=number_of_columns; j++)
    {
      //shifting each element of array of subset towards right so as to add first element of input array.
      output[i + ans][j + 1] = output[i][j];
    }
  }

  return 2 * ans;

}

int main()
{
  int input[20], length, output[35000][20];
  cin >> length;
  for (int i = 0; i < length; i++)
    cin >> input[i];

  int size = subset(input, length, output);

  for (int i = 0; i < size; i++)
  {
    for (int j = 1; j <= output[i][0]; j++)
    {
      cout << output[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}