#include<bits/stdc++.h>
using namespace std;
int sumOfDigits(int n){
    if(n==0){return 0;}
    int k=n%10;
    int ans=sumOfDigits(n/10);
    return ans+k;
}

int main(){
    int n;
    cin>>n;
    cout<<sumOfDigits(n);

    return 0;
}