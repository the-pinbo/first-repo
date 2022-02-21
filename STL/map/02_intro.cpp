#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<int, string> m;
  m.insert({5, "GFG"});
  m.insert({50, "inba"});
  m.insert({51, "ehoi"});
  auto it = m.find(5);
  it == m.end() ? cout << "not found" : cout << "found";
  cout << (*it).first << " " << (*it).second << endl;
  m.count(5) == 0 ? cout << "found" : cout << "not found";
  it = m.upper_bound(7);
  cout << (*it).first << " " << (*it).second << endl;
  it = m.upper_bound(7);
  cout << (*it).first << " " << (*it).second << endl;
  m.erase(it);
  m.erase(51);
  m.erase(m.begin(), m.end());
  return 0;
}