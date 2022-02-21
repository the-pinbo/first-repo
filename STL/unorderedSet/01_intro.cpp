#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
  unordered_set<int> s;
  s.insert(10);
  s.insert(20);
  s.insert(30);
  s.insert(40);
  s.insert(50);
  for (auto x : s)
    cout << x << endl;
  return 0;
}