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
  l.assign({10, 20, 30, 10});
  print(l);
  l.remove(10);
  for (forward_list<int>::iterator it{l.begin()}; it != l.end(); ++it)
  {
    cout << *it << "  ";
  }
  cout << endl;
  forward_list<int> l2;
  l2.assign(l.begin(), l.end());
  print(l2);
  forward_list<int> l3;
  l3.assign(5, 40);
  print(l3);
  return 0;
}