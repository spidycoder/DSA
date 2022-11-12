#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        cout << "Capacity " << v.capacity() << endl;
        cout << "Size " << v.size() << endl;
        v.push_back(i + 1);
        cout << v[i] << endl;
    }
    // insertion of elements
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    // deletion of element from behind
    v.pop_back();
    // we should never use [] for insertion of element in vector
    v[3] = 40;
    v.push_back(40);
    // printing elements
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v.at(2) << endl;
    cout << v.size() << endl;

    return 0;
}