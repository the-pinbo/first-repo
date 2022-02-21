#include <bits/stdc++.h>
using namespace std;

int naivePartition(vector<int> &vec, int p)
{
  int pivot = vec.at(p);
  vector<int> new_vec(vec.size());
  int i = 0, k = 0;
  while (i < vec.size())
  {
    if (vec.at(i) <= pivot)
      new_vec.at(k++) = vec.at(i++);
    else
      i++;
  }
  i = 0;
  while (i < vec.size())
  {
    if (vec.at(i) == pivot)
      new_vec.at(k++) = vec.at(i++);
    else
      i++;
  }
  int index = k;
  new_vec.at(k++) = pivot;
  i = 0;
  while (i < vec.size())
  {
    if (vec.at(i) > pivot)
      new_vec.at(k++) = vec.at(i++);
    else
      i++;
  }
  vec = new_vec;
  return k;
}

int naivePartition(vector<int> &vec, int p, int low, int high)
{
  int pivot = vec.at(p);
  int vec_size = high - low + 1;
  vector<int> new_vec(vec_size);

  int i = low, k = 0;
  while (i <= high)
  {
    if (vec.at(i) < pivot)
      new_vec.at(k++) = vec.at(i++);
    else
      i++;
  }

  i = low;
  while (i <= high)
  {
    if (vec.at(i) == pivot)
      new_vec.at(k++) = vec.at(i++);
    else
      i++;
  }

  int index = k;
  new_vec.at(k++) = pivot;

  i = low;
  while (i <= high)
  {
    if (vec.at(i) > pivot)
      new_vec.at(k++) = vec.at(i++);
    else
      i++;
  }

  for (i = low; i <= high; ++i)
    vec.at(i) = new_vec.at(i);

  return k;
}

int hoarePartition(vector<int> &vec, int low, int high)
{
  int pivot = vec.at(low);
  int i, j;
  for (i = low + 1, j = high; i > j;)
  {
    if (vec.at(i) <= pivot and vec.at(j) > pivot)
      i++, j--;
    else if (vec.at(i) > pivot and vec.at(j) <= pivot)
      swap(vec.at(i++), vec.at(j--));
    else if (vec.at(i) > pivot and vec.at(j) > pivot)
    {
      j--;
      continue;
    }
    else
    {
      i++;
      continue;
    }
  }
  return i;
}

int lomutoPartition(vector<int> &vec, int low, int high)
{
  int pivot = vec.at(high);
  int len = 0;
  for (int i = 0; i < vec.size() - 1; i++)
  {
    if (vec.at(i) < pivot)
      swap(vec.at(i), vec.at(len++));
  }
  swap(vec.at(vec.size() - 1), vec.at(len));
  return len;
}
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