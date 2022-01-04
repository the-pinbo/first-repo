#include <bits/stdc++.h>
using namespace std;

bool myCmp(pair<string, double> p1, pair<string, double> p2)
{
  return p1.second > p2.second;
}

int main()
{
  vector<pair<string, double>> vec;
  cout << "Do you want to enter marks[y/n]: " << flush;
  string ch;
  cin >> ch;
  while (ch == "y" or ch == "Y")
  {
    string rollNo{};
    double marks{};
    cout << "Enter rollNo followed by marks." << endl;
    cin >> rollNo >> marks;
    vec.push_back(make_pair(rollNo, marks));
    cout << "Do you want to enter marks again[y/n]: " << flush;
    cin >> ch;
  }
  sort(vec.begin(), vec.end(), myCmp);
  for (auto &v : vec)
  {
    cout << v.first << "  " << v.second << endl;
  }
  return 0;
}