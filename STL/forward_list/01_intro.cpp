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
  forward_list<int> l = {10, 20, 30, 40};
  print(l);
  l.push_front(5);
  l.push_front(3);
  print(l);
  l.pop_front();
  print(l);
  return 0;
}