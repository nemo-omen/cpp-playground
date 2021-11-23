#include <vector>
#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
  vector<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int>::iterator begin = values.begin(), end = values.end();
  
  cout << "begin: " << *begin << '\n' << "end: " << *end << '\n';
  while(begin != end) {
    cout << *begin << '\n';
    begin++;
  }
  return 0;
}