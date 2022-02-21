#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b)
{
  int i = 0, j = 0, k = 0;
  vector<int> vec(a.size() + b.size());

  while (i < a.size() and j < b.size())
  {
    if (a.at(i) <= b.at(j))
      vec.at(k++) = a.at(i++);
    else
      vec.at(k++) = a.at(j++);
  }
  while (i < a.size())
    vec.at(k++) = a.at(i++);
  while (j < b.size())
    vec.at(k++) = a.at(j++);
  return vec;
}

void merge(vector<int> &vec, int low, int high)
{
  int mid = low + (high - low) / 2;
  vector<int> a{vec.begin() + low, vec.begin() + mid};
  vector<int> b{vec.begin() + mid, vec.begin() + high};

  int i = 0, j = 0, k = 0;

  while (i < a.size() and j < b.size())
  {
    if (a.at(i) <= b.at(j))
      vec.at(k++) = a.at(i++);
    else
      vec.at(k++) = b.at(j++);
  }
  while (i < a.size())
    vec.at(k++) = a.at(i++);
  while (j < b.size())
    vec.at(k++) = b.at(j++);
  return;
}
void mergeSort(vector<int> &vec, int low, int high)
{
  if (high > low)
  {
    int mid = low + (high - low) / 2;
    mergeSort(vec, low, mid);
    mergeSort(vec, mid, high);
    merge(vec, low, high);
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
  mergeSort(arr, 0, arr.size());
  for (auto &x : arr)
  {
    cout << x << "  ";
  }
  cout << endl;

  return 0;
}