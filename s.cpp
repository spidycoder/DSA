#include <iostream>
using namespace std;

bool checkNumber(int input[],int size,int x){
    for (int i = 0; i < size; i++)
    {
        if (input[i]==x)
        {
            return true;
        }
        else{
            return false;
        }
        
    }
    
}
bool checkNumber(int input[], int size, int x) {
     for (int i = 0; i < size; i++)
   {
    if(input[i]==x){
        return true;}
   }
    return false;
   
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */

}
bool checkNumber(int arr[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    if (size==0){
        return false;
    }
    if(arr[size-1]==x){
        return true;
    }
   return checkNumber(arr, size-1,x);
    //return checkNumber;
}
bool checkNumber(int arr[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    if (size==0){
        return false;
    }
    if(arr[0]==x){
        return true;
    }
   return checkNumber(arr+1, size-1,x);
    //return checkNumber;
}

int main()
{
    int n;
    cin>>n;
    int *input=new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>input[i];
    }
    int x;
    cin>>x;
    if (checkNumber(input,n,x))
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
    delete []input;
}