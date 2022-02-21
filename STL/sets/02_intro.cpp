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
  auto it = s.lower_bound(3);
  cout << "Lower bound of 3 is " << *it << endl;
  it = s.upper_bound(11);
  cout << "Upper bound of 11 is " << *it << endl;
  return 0;
}