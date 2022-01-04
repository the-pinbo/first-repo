#include <iostream>
#include <list>
using namespace std;

class DataStruct
{
private:
  list<int> li;

public:
  void insert(int x)
  {
    li.emplace_back(x);
  }
  void print()
  {
    cout << "{";
    for (auto &x : this->li)
    {
      cout << x << ",";
    }
    cout << "}" << endl;
  }
  void replace(int x, list<int> &seq)
  {
    // for (list<int>::iterator it = this->li.begin(); it != this->li.end(); ++it)
    // {
    //   if (*it == x)
    //   {
    //     it = this->li.erase(it);
    //     for (auto &x : seq)
    //       insert(x);
    //     break;
    //   }
    // }
    auto it = find(this->li.begin(), this->li.end(), x);
    if (it == li.end())
      return;
    it = li.erase(it);
    li.insert(it, seq.begin(), seq.end());
  }
};
