#include<bits/stdc++.h>
using namespace std;

template <typename T>
class QueueUsingArray{
    T *data;
    int FirstIndex;
    int NextIndex;
    int size;
    int capacity;
    public:
    //creating a constructor
    QueueUsingArray(int s){
        //initialising the values
        data=new T[s];
        FirstIndex=-1;
        NextIndex=0;
        size=0;
        capacity=s;

    }
    //public functions of Queue
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    //insertion
    void enqueue(T element){
        //base case
        if(size==capacity){
            cout<<"Queue is Full!"<<endl;
            return;
        }
        data[NextIndex]=element;
        //when nextIndex==capacity,then we will increment nextIndex in circular way
        NextIndex=(NextIndex+1)%capacity;
        size++;
        if(FirstIndex==-1){
            FirstIndex=0;
        }
    }
    //deletion
    T dequeue(){
        //base case
        if(size==0){
            cout<<"Queue is Empty"<<endl;
            FirstIndex=-1;
            NextIndex=0;
            return 0;
        }
        T ans = data[FirstIndex];
        FirstIndex=(FirstIndex+1)%capacity;
        size--;
        return ans;
    }
    //getting front element
    T front(){
        //base case
        if(size==0){
            return 0;
        }
        return data[FirstIndex];
    }


};
int main() 
{
    QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);


    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
return 0;
}