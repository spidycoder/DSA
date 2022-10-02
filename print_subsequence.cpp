#include<bits/stdc++.h>
using namespace std;

void print_subseq(string input,string output){
    if(input.length()==0){
        cout<<output<<endl;
        return ;
    }
    //calling function and not including first character.
    print_subseq(input.substr(1),output);
    //calling function again and including first character.
    print_subseq(input.substr(1),output+input[0]);
}

int main(){
    string input;
    cin>>input;
    string output=" ";
    print_subseq(input,output);

    return 0;
}