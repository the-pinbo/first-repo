#include <bits/stdc++.h>
using namespace std;

void mergeSort(vector<int> &vec)
{
  vector<int>::iterator max;
  for (auto it = vec.end() - 1; it != vec.begin(); --it)
  {
    max = max_element(vec.begin(), it + 1);
    auto temp = *it;
    *it = *max;
    *max = temp;
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