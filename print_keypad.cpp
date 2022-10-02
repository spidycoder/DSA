#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

string input[]={" ", " ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


//creating a function which will store stings in output string array.
void printKeypad2(int num,string output){
    //Base Case
    if(num==0 || num==1){
        cout<<output<<endl;
        return;
    }
    //finding last digit
    int k=num%10;
    //finding string at last digit
    string a=input[k];
    //iterating over the string at last digit
    for(int i=0;i<a.size();i++){
        //calling recursive call and adding strings at last digit to all strings from recursion call
        printKeypad2(num/10,input[i]+output);
    }
}

void printKeypad(int num){
    //base case.
    if(num==0||num==1){
        return;
    }
    //calling recursive function.
    printKeypad2(num,"");
   
}


int main(){
    int num;
    cin >> num;

    printKeypad(num);
    return 0;
}