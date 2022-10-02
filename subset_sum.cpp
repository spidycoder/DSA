#include <iostream>

using namespace std;


// int subsetSumToK(int input[], int n, int output[][50], int k) {
//     // Write your code here


// }


int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  for(int i=0;i<length;i++){
    for(int j=i+1;j<length;j++){
        if(input[i]+input[j]==k){
            cout<<input[i]<<" "<<input[j];
        }
    }cout<<endl;
  }
}
