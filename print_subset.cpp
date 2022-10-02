/*
Given an integer array (of length n), find and print all the subsets of input array.
*/

#include <bits/stdc++.h>
using namespace std;

void printSubsetsOfArray(int input[],int size,int output[],int m){
    //base case
    if(size==0)
    {
        //printing the array
        for(int i=0;i<m;i++)
            cout<<output[i]<<" ";
        cout<<endl;
        return;
    }
    //creating a new output array to sore the outcomes of recursion call.
    // 'm' is the size of output array
    int newoutput[m+1];
    int i;
    for(i=0;i<m;i++)
        //making copy of output array and storing all elements of output array in new output array
        newoutput[i]=output[i];
    //adding first element in new output array.
    newoutput[i]=input[0];
    //after adding first element of input array in new output array,size of new output array is increased by one so passing 'm+1' 
    printSubsetsOfArray(input+1,size-1,newoutput,m+1);
    //printing the final output
    printSubsetsOfArray(input+1,size-1,output,m);
}
void printSubsetsOfArray(int input[], int size) {
	
    int output[100];
    printSubsetsOfArray(input,size,output,0);
    
    
}



int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
    return 0;
}