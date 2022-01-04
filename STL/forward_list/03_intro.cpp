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
  print(l);
  auto it = l.insert_after(l.begin(), 10);
  cout << *it << endl;
  print(l);
  it = l.insert_after(it, {15, 20, 30});
  cout << *it << endl;
  print(l);
  // always use emplece_after instead of insert_after
  it = l.emplace_after(it, 40);
  print(l);
  it = l.erase_after(it);
  cout << *it << endl;
  print(l);
  it = l.erase_after(it, l.end());
  print(l);
  return 0;
}