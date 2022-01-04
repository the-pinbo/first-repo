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
  list<int> l{10, 2, 5, 20};
  l.pop_front();
  print(l);
  l.pop_back();
  print(l);
  cout << "{";
  for (auto it = l.rbegin(); it != l.rend(); ++it)
    cout << *it << ", " << flush;
  cout << "\b}" << endl;
  list<int>::iterator it{l.begin()};
  it++;
  cout << *(++it) << endl;
  l.insert(it, {1, 4, 7, 2, 5, 8});
  print(l);
  cout << *it << endl;
  cout << l.front() << "  " << l.back() << endl;
  cout << l.size() << endl;
  cout << *(--it) << endl;
  it = l.erase(--it);
  cout << *(it) << endl;
  // system("clear");
  print(l);
  l.remove(2);
  print(l);
  list<int> l2;
  l2.assign({10, 20, 30, 40});
  l.assign({1, 2, 3, 4, 5});
  l.merge(l2);
  print(l);
  print(l2);
  return 0;
}
