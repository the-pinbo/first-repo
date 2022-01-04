#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> vec{20, 40, 30, 10};
  vector<pair<int, int>> vec2;
  for (int i{0}; i < vec.size(); ++i)
  {
    vec2.push_back(make_pair(vec.at(i), i));
  }
  sort(vec2.rbegin(), vec2.rend());
  for (auto p : vec2)
    cout << p.second << "  " << p.first << endl;

  return 0;
}