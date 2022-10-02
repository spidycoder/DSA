#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary,char destination)
{
    if(n==0){return ;}
    if (n == 1)  //This is the base case.
    {
        cout<<source<<" "<<destination<<endl;
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary); //(n-1) discs transferred from source to auxilary and this is done by recursion
    cout << source <<" "<< destination << endl;  //now 1 disc is transferred from source to destination by us
    
    towerOfHanoi(n - 1, auxiliary, source, destination);//(n-1) discs are now transferred from auxilary to destination by using recursion using source rod
}

int main()
{
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}