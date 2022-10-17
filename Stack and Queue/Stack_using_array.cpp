#include<bits/stdc++.h>
using namespace std;

//creating a class 
class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;
    public:
      //constructor
      StackUsingArray(int totalSize){
        //initialising the size of array
        data=new int[totalSize];
        //initialising nextIndex with 0
        nextIndex=0;
        //initialisng
        capacity=totalSize;
      }
      //size() function
      int size(){
        return nextIndex;
      }
      //isEmpty() function
      bool isEmpty(){
        /*
        if(nextIndex==0){
            return true;
        }
        else{
            return false;
        }
        */
       //shorter way to write above codes
       return nextIndex==0;
      }
      //push() function
      void push(int element){
        if(nextIndex>=capacity){
            return;
        }

        else{
            data[nextIndex]=element;
            nextIndex++;
        }
      }
      //pop()
      int pop(){
        if(nextIndex==0){
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
      }

      //top()
      int top(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
      }
};


int main() 
{
    StackUsingArray s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
   
return 0;
}