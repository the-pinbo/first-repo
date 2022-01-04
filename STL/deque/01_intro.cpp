#include <deque>
#include <iostream>
using namespace std;

int main()
{
  deque<int> dq = {10, 20, 30};
  dq.push_back(50);
  dq.push_front(5);
  for (auto x : dq)
    cout << x << "  " << endl;
  return 0;
}