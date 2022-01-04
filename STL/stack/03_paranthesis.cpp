#include <bits/stdc++.h>
using namespace std;

string stockSpan(string &str)
{
  stack<char> st;
  st.push(str.at(0));
  for (int i = 1; i < str.size(); ++i)
  {
    if (str.at(i) == 40 or str.at(i) == 91 or str.at(i) == 123)
    {
      st.push(str.at(i));
      continue;
    }
    if (st.top() == '(' and str.at(i) == ')' or st.top() == '[' and str.at(i) == ']' or st.top() == '{' and str.at(i) == '}')
      st.pop();
    else
      return "NO";
  }
  if (st.empty())
    return "YES";
  return "NO";
}

int main()
{
  string str = "))(";
  cout << stockSpan(str) << endl;
  return 0;
}