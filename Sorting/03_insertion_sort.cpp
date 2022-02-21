#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int> &vec)
{
  for (int len = 1; len < vec.size(); ++len)
  {
    for (int i = 0; i < len; ++i)
    {
      if (vec.at(i) > vec.at(len))
      {
        int v = vec.at(len);
        for (int j = len; j > i; --j)
        {
          vec.at(j) = vec.at(j - 1);
        }
        vec.at(i) = v;
        break;
      }
    }
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