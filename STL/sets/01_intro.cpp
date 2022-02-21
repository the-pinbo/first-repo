#include <iostream>
#include <set>
using namespace std;

int main()
{
  set<int> s;
  s.insert(10);
  s.insert(5);
  s.insert(20);
  s.emplace(-10);
  for (auto &x : s)
    cout << x << endl;
  set<int, greater<int>> s2;
  s2.insert(10);
  s2.insert(5);
  s2.insert(20);
  s2.emplace(-10);
  for (set<int>::iterator it{s2.begin()};
       it != s2.end();
       ++it)
  {
    cout << *it << endl;
  }
  s2.clear();
  cout << s2.size() << "This is the size of s2" << endl;
  auto it = s.find(10);
  if (it != s.end())
    cout << "Element found at " << *it << endl;
  s.erase(5);
  for (auto &x : s)
    cout << x << endl;
  s.erase(it, s.end());
  return 0;
}