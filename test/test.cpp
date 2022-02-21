#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;
class Timer
{
private:
  chrono::time_point<chrono::steady_clock> start, end;
  chrono::duration<double> duration;

public:
  Timer()
  {
    start = chrono::high_resolution_clock::now();
  }
  ~Timer()
  {
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Timer took " << duration.count() << "s " << endl;
  }
};

int main()
{
  Timer time;
  cout << "Hello world" << endl;
  return 0;
}