/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
*/

#include <iostream>
#include <math.h>
using namespace std;

#include <string.h>
using namespace std;

#include <string.h>
using namespace std;
//function to convert string to interger
int atoi(char a){
    int i= a- '0';
    return i;
}
//function to map corresponding character to each iterger.
char itoa(int i){
    char c='a'+i-1;
    return c;
}
int getCodes(string input, string output[10000]){
    //base case
    if(input.size()==0){
        output[0]="";
        return 1;
    }
    //if size of interger is 1 then only one permutation will be possible
    if(input.size()==1){
        output[0]=itoa(atoi(input[0]));
        return 1;
    }
    //creating two temporary string array to store the values returned from recursive call.
    string result1[10000],result2[10000];
    //declaring the size of result2 as 0 because if interger length is 1 the we will not need result2.
    int size2=0;
    //recursive call for result1 in which we are passing whole interger except first string.
    int size1=getCodes(input.substr(1),result1);
    //checking the size of interger
    if(input.size()>1){
        //if size of interger is greater than 10 and less than 26 the we can consider first digit as pair.
        if(atoi(input[0])*10+atoi(input[1])>=10&&atoi(input[0])*10+atoi(input[1])<27){
            size2=getCodes(input.substr(2),result2);
        }
    }
    //initializing the index of output array.
    int k=0;
    //adding the first character corresponding to first character to each character returned from result1.
    for(int i=0; i<size1; i++){
        output[k++]=itoa(atoi(input[0]))+result1[i];
    }
    //adding the first character corresponding to first character to each character returned from result1.
    for(int i=0; i<size2; i++){
        output[k++]=itoa(atoi(input[0])*10+atoi(input[1]))+result2[i];
    }
    //returning the final size of output array.
    return k;
}

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
