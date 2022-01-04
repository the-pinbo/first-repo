#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k)
{
  list<int> l;
  for (int i = 0; i < n; ++i)
    l.emplace_back(i);
  list<int>::iterator it{l.begin()};
  while (!(l.size() == 1))
  {

    for (int i = 1; i < k; ++i)
    {
      it++;
      if (it == l.end())
        it = l.begin();
    }
    cout << *it << " is dead" << endl;
    if (*it == l.back())
    {
      l.erase(it);
      it = l.begin();
    }
    else
      it = l.erase(it);
  }
  return *it;
}

int main()
{
  int n, k;
  cin >> n >> k;
  cout << solve(n, k) << " is the only person left" << endl;
  return 0;
}