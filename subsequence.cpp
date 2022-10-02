#include<bits/stdc++.h>
using namespace std;

int subseq(string input,string output[]){
    //Base case
    if(input.empty()){
        output[0]="";
        return 1;
    }
    //creating a small string expect the first character
    string smallString=input.substr(1);
    //finding the size of half subsequence
    int smallOutputSize=subseq(smallString,output);
    //making copy of output form recursion call and adding the first element at all strings.
    for (int i = 0; i < smallOutputSize; i++)
    {
        output[i+smallOutputSize]=input[0]+output[i];
    }
    //returning the size of subsequence array.
    return 2*smallOutputSize;
}

int main(){
    string input;
    cin>>input;
    string* output=new string[100];
    int count=subseq(input,output);
    for (int i = 0; i < count; i++)
    {
        cout<<output[i]<<endl;
    }
    
}