#include <iostream>
#include <forward_list>
using namespace std;

void print(forward_list<int> &l)
{
  for (auto &x : l)
    cout << x << "  ";
  cout << endl;
}

int main()
{
  forward_list<int> l{1, 3, 0, 0, 1, 3};
  forward_list<int> l2 = {10, 20, 30, 40};
  print(l);
  l.reverse();
  print(l);
  l.merge(l2);
  print(l);
  l.sort();
  print(l);
  l.clear();
  print(l);
  l.empty() ? cout << "Empty" << endl : cout << "Not empty" << endl;
  return 0;
}