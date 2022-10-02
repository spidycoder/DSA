#include<iostream>
using namespace std;


#include <string.h>
using namespace std;

void helper(string input,string output){
    if(input.size()==0){
        cout<<output<<endl;
        return;
    }
    //converting character to interger
    int num = input[0] - 48; 
    //converting interger into character
    char ch = num - 1 + 'a';
    //calling recursion for string except first charcter
    helper(input.substr(1),output+ch);
    //checking if string lenght is 1 or not
    if(input[1] != '\0'){ 
        //when string lenght is not one,then convert first two character into interger and then into character
        num = num * 10 + input[1] - 48;
        ch = num - 1 + 'a';
        //if first two character of string is between 10 and 26 the call recursion for taking these two strings as on one string
        if(num >= 10 && num <= 26)
        {
            helper(input.substr(2),output+ch);
        }
    }
  }
  
    


void printAllPossibleCodes(string input) {
   helper(input,"");
   
}


int main(){
     string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}