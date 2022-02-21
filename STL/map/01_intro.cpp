#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<int, int> m;
  m.insert({10, 20});
  m[5] = 100;
  m.insert({3, 300});
  m.insert({3, 200});

  for (auto x : m)
    cout << x.first << " " << x.second << endl;

  cout << m[0] << endl;
  m[0] = 10;
  cout << m[0] << endl;
  m.at(10) = 300;
  cout << m.at(10) << endl;
  cout << m.at(100) << endl;
  return 0;
}