#include <bits/stdc++.h>
using namespace std;

template <typename T, typename V>
class Pair
{
   T x;
   V y;

public:
   T getX()
   {
      return x;
   }
   void setX(T x)
   {
      this->x = x;
   }
   V getY()
   {
      return y;
   }
   void setY(V y)
   {
      this->y = y;
   }
};
int main()
{
   // creating a pair
   // Pair<int, int> p1;
   // p1.setX(10);
   // p1.setY(20);
   // creating a triplet using pair
   Pair<Pair<int, int>, int> p2;
   p2.setY(10);
   Pair<int, int> p3;
   p3.setX(3);
   p3.setY(4);
   p2.setX(p3);
   cout<<p2.getX().getX()<<" "<<p2.getX().getY()<<" "<<p2.getY();
   return 0;
}