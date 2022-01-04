#include <bits/stdc++.h>
using namespace std;

int main()
{
  stack<int> s;
  cout << "Enter the string: ";
  string word;
  cin >> word;
  for (auto &c : word)
  {
    s.push(c);
  }
  word = "";
  while (!s.empty())
  {
    word += s.top();
    s.pop();
  }
  cout << word << endl;

  return 0;
}