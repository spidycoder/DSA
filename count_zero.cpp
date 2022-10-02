#include<bits/stdc++.h>
using namespace std;

int countZero(int n){
    if(n==0){return 0;}
    int ans=countZero(n/10);
    if(n%10==0){
        return ans+1;
    }
    else{
        return ans;
    }
    
}

int main(){
    int n;
    cin>>n;
    cout<<countZero(n);
    return 0;
}