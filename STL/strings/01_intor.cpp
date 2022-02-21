#include <bits/stdc++.h>
using namespace std;
int main()
{
  string name;
  cout << "Enter your name: " << flush;
  getline(cin, name);
  cout << "Your name is " << name << endl;
  cout << "Enter text: " << flush;
  getline(cin, name, '$');
  cout << "The text is: " << name << endl;
  return 0;
}