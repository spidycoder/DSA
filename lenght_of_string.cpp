#include<bits/stdc++.h>
using namespace std;

int length(char s[]){
    if(s[0]=='\0'){return 0;}
    int ans=length(s+1);
    return ans+1;
}
int main(){
    char str[100];
    cin>>str;
    cout<<length(str);
    return 0;
}