#include <iostream>
#include <math.h>
using namespace std;

#include <string>
using namespace std;

#include <string>
using namespace std;

int returnPermutations(string input, string output[])
{

    int len = input.length();
    if (len == 0)
    {
        output[0] == " "; // base case
        return 1;
    }

    string soutputsize[1000]; // creating a store array

    int ssize = returnPermutations(input.substr(1), soutputsize); // permutation after
    // remove first character
    //creating index for output array
    int k = 0;
    for (int i = 0; i < ssize; i++)
    { // input[0] ko chodkar whole size
        for (int j = 0; j <= soutputsize[i].length(); j++)
        { // for storing in creating array string

            /*  storing in output array and adding the first character of input string */
            output[k++] = soutputsize[i].substr(0, j) + input[0] + soutputsize[i].substr(j);
        }
    }
    return k;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}