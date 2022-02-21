#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int> &vec)
{
  bool flag{false};
  for (int len{vec.size() - 1}; len > 0; len--)
  {
    flag = false;
    for (int i{0}; i < len; ++i)
    {
      if (vec.at(i) > vec.at(i + 1))
      {
        swap(vec.at(i), vec.at(i + 1));
        flag = true;
      }
    }
    if (!flag)
      return;
  }
}

int main()
{
  cout << "Enter the size of the array: ";
  int n{0};
  cin >> n;
  vector<int> arr(n);
  cout << "Enter the elements of array:\n";
  for (auto &x : arr)
  {
    cin >> x;
  }
  cout << "The sroted array is:\n";
  mergeSort(arr);
  for (auto &x : arr)
  {
    cout << x << "  ";
  }
  cout << endl;

  return 0;
}