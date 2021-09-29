#include <bits/stdc++.h>
#include <string>

#include "LinkedList.h"
using namespace std;

int main(int argc, const char** argv) {

  LinkedList<int> lli;  // int LinkedList
  cout << lli;
  lli.push_front(123);
  cout << lli;
  lli.push_front(456);
  lli.push_front(789);
  lli.push_back(112);
  lli.pop_back();
  
  Node<int> fives = Node<int>(555);

  // cout << "lli.tail: " << lli.tail << endl;

  // cout << &lli;
  cout << lli;
  return 0;
}