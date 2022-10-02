/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
*/
#include <bits/stdc++.h>
using namespace std;

#include <string>
using namespace std;
string input[]={" ", " ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int num,string output[]){
    //base case
    if(num==0||num==1){
        output[0]="";
        return 1;
    }
    //creating a small string ouput to store all strings returned from recursion call.
    string smallOutput[10000];
    //getting the size of array of strings returned from recursion call
    int smallOutputSize=keypad(num/10,smallOutput);
    //getting the last digit of number
    int k=num%10;
    //storing the string at k in currentString array
    string currentString=input[k];
    //setting index for output array.
    int p=0;
    //traversing the string at k.
    for (int i = 0; i < currentString.size(); i++)
    {
        //storing the first character in currentChar.
        char currChar=currentString[i];
        //traversing the array of string returned from recursion call.
        for(int j=0;j<smallOutputSize;j++){
            //adding each character of string at k to array of strings returned from recursion call.
            output[p]=smallOutput[i]+currChar;
            p++;
        }
    }
    return p;  //p will give size of final array of strings.


}

// int keypad(int num, string output[]){
//     /* Insert all the possible combinations of the integer number into the output string array. You do not need to
//     print anything, just return the number of strings inserted into the array.
//     */
//     int x=num%10;
//     //base case
//     if(x==0 ||x==1)
//     {     output[0]="";
//           return 1;
//     }
    
//     int SizeOfSmall=keypad(num/10,output);
//     for(int i=1;i<key[x].size();i++){
//         for(int j=0;j<SizeOfSmall;j++){
//             output[SizeOfSmall*i+j]=output[j];
//         }
//     }
//     for(int i=0;i<key[x].size();i++){
//         for(int j=0;j<SizeOfSmall;j++){
//             output[SizeOfSmall*i+j]=output[SizeOfSmall*i+j]+key[x][i];
//         }
//     }
//     return SizeOfSmall*key[x].size();
    
// }

//TA approach
// #include <string>
// using namespace std;

// int keypad(int num, string output[])
// {
//     string str;
    
//     if (num == 0) {
//         output[0] = "";
//         return 1;
//     }
    
//     int n = num % 10;
//     num /= 10;
    
//     int smallAns = keypad(num, output);
    
//     switch (n) {
//         case 2 : str = "abc";
//             break;
//         case 3 : str = "def";
//             break;
//         case 4 : str = "ghi";
//             break;
//         case 5 : str = "jkl";
//             break;
//         case 6 : str = "mno";
//             break;
//         case 7 : str = "pqrs";
//             break;
//         case 8 : str = "tuv";
//             break;
//         case 9 : str = "wxyz";
//             break;
//     }
    
//     int finalSize = smallAns * str.size();
//     string ans[finalSize];
    
//     int k = 0;
//     for (int i = 0; i < smallAns; ++i) {
//         for (int j = 0; j < str.size(); ++j) {
//             ans[k++] = output[i] + str[j];
//         }
//     }
    
//     for (int i = 0; i < finalSize; ++i) {
//         output[i] = ans[i];
//     }
    
//     return finalSize;
// }

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}