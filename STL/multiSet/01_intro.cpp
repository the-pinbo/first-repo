#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
  multiset<int> ms;
  ms.insert(10);
  ms.insert(20);
  ms.insert(50);
  ms.insert(5);
  for (auto x : ms)
    cout << x << " ";
  ms.insert(5);
  ms.insert(5);
  cout << endl
       << ms.count(5) << endl;
  auto it = ms.lower_bound(11);
  cout << *it << endl;
  it = ms.upper_bound(9);
  cout << *it << endl;
  auto it2 = ms.equal_range(5);
  cout << *it2.first << " " << *it2.second << endl;
  return 0;
}