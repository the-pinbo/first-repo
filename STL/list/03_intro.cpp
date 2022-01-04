#include <iostream>
#include <list>
using namespace std;
void print(list<int> &l)
{
  for (int &x : l)
    cout << x << "  ";
  cout << endl;
}

int main()
{
  list<int> l{10, 15, 15, 20, 20, 10};
  print(l);
  l.unique();
  print(l);
  l.sort();
  print(l);
  l.reverse();
  print(l);
  return 0;
}
