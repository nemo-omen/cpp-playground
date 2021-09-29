#include <bits/stdc++.h>
#include <string>

#include "LinkedList.h"
using namespace std;

int main(int argc, const char** argv) {

  LinkedList<int> lli;  // int LinkedList
  cout << lli;
  lli.push_front(123);
  lli.push_front(456);
  lli.push_front(789);
  lli.push_back(112);
  lli.pop_back();
  lli.insert(333, 1);
  lli.insertAfter(444, 1);
  lli.insertBefore(666, 1);
  cout << lli;

  cout << lli.find(666) << endl;
  Node<int>* found = lli.find(112);
  cout << found << endl;
  return 0;
}