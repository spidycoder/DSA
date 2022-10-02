#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


//My partation function
int partition(int *arr,int si,int ei){
    int pivot=arr[si];
    int small_num_than_pivot=0;
   
    //counting the elements which are smaller than pivot element.
    for (int i = si+1; i <=ei; i++)
    {
        if(pivot>=arr[i]){
            small_num_than_pivot++;
        }
    }
     int pivotIndex=small_num_than_pivot+si;
    //swapping the first and position of pivot element
    swap(arr[0],arr[small_num_than_pivot+si]);
    //swapping the elements which are larger than pivot and at left side and for right side
    int i=si;
    int j=ei;
    while (i<pivotIndex && j>pivotIndex)
    {
        if(arr[i]<=pivot){
            i++;
        }
        else if(arr[j]>pivot){
            j--;

        }
        else{
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    
    return pivotIndex;
}

//another partation function
int partition(int *input,int start,int end){
      int pivot=input[start];
      int count =0;
      for(int i=start+1;i<=end;i++)
      {
          if(input[i]<=pivot)
        {
          count++;
        }
      } 
        int pivotIndex=start+count;
        int temp=input[start];
        input[start]=input[pivotIndex];
        input[pivotIndex]=temp;

        int i=start;
        int j=end;
        while(i<pivotIndex && j>pivotIndex)
        {
          if(input[i]<=pivot)
         {
            i++;
          }
          else if(input[j]>pivot)
           {
            j--;
           }
            else 
              {
              int tempo=input[i];
              input[i]=input[j];
              input[j]=tempo;
              i++;
              j--;
            }
          }

    return pivotIndex;  
    
}

void quickSorthelper(int *arr,int si,int ei){
    if(si>=ei){
        return ;
    }
   int c= partition(arr,si,ei);
   quickSorthelper(arr,si,c-1);
   quickSorthelper(arr,c+1,ei);
    
}

void quickSort(int input[],int size){
    quickSorthelper(input,0,size-1);


}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;
    
    
    return 0;
}