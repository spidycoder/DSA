#include <bits/stdc++.h>

using namespace std;
int allIndexes(int input[],int n,int x,int output[]){
    if(n==0){return 0;}
    
    int ans=allIndexes(input+1,n-1,x,output); //Here ans will give size of output array
    
    //incrementing each element of output array by 1.
    for(int i=0;i<ans;i++){
        output[i]++;
    }
    //checking for first element.
    if(input[0]==x){
        //shifting the output array towards right by each position and adding one 0 at first inedex and incrementing size of output array.
        for (int i = ans; i>0; i--)
        {
            output[i]=output[i-1];
        }output[0]=0;
        ans++;
        return ans;
        

    }
    else{
           return ans;
    }

}
int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int x;

    cin >> x;

    int *output = new int[n];

    int size = allIndexes(input, n, x, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;

    delete[] output;
}