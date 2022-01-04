#include <bits/stdc++.h>
using namespace std;

void printSortedMarks(int *marks, string *rollNo, const int n)
{
  vector<pair<int, string>> pairVec(n);
  for (int i = 0; i < n; ++i)
  {
    pairVec.at(i) = {marks[i], rollNo[i]};
  }
  sort(pairVec.begin(), pairVec.end());
  for (auto &p : pairVec)
    cout << p.second << "  " << p.first << endl;
}

int main()
{
  int marks[] = {99, 15, 55, 60, 70, 85, 100};
  int n = 7;
  string rollNo[] = {
      "201XX001",
      "201XX002",
      "201XX003",
      "201XX004",
      "201XX005",
      "201XX006",
      "201XX007",
  };
  printSortedMarks(marks, rollNo, n);
  return 0;
}