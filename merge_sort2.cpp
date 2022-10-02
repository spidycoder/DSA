#include<bits/stdc++.h>
using namespace std;

void merge(int *arr,int si,int ei){
    int mid=(si+ei)/2;
    //creating two array for storing two sorted array
    int len1=mid-si+1;
    int len2=ei-mid;
    int *first=new int[len1];
    int *second=new int[len2];

    //copy values
    int mainArrayIndex=si;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
        
    }
    int mainArrayIndex=mid+1;
    for(int i=0;i<len2;i++){
        second[i] = arr[mainArrayIndex++];
    }
    //merging two sorted arrays
    //creating indexes for two arrays
    int index1=0;
    int index2=0;
    mainArrayIndex=si;
    while (index1<len1&&index2<len2)
    {
        if(first[index1]<second[index2]){
            arr[mainArrayIndex]=first[index1++];
        }
        else{
            arr[mainArrayIndex++]=second[index2++];
        }
    }
    while (index1<len1)
    {
        arr[mainArrayIndex++]=first[index1++];
    }
    while (index2<len2)
    {
        arr[mainArrayIndex++]=second[index2++];
    }
    delete []first;
    delete []second;
    
    

}

void mergeSortHelper(int *arr[],int si,int ei){
    if(si>ei){return ;}
    //finding mid element
    int mid=(si+ei)/2;
    //sorting left part of array
    mergeSortHelper(arr,si,mid);
    mergeSortHelper(arr,mid+1,ei);
}
void mergeSort(int input[],int size){

}
int main(){
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    //mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}