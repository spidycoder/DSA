#include<bits/stdc++.h>
using namespace std;

int multiply(int a,int b){
    if(a==0||b==0){
        return 0;
    }
    int ans=multiply(a,b-1);
    return ans+a;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<multiply(a,b);

    return 0;
}