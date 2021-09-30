#include <string>
#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
  // int luckyNumbers[5];

  // cout << luckyNumbers << endl; // will print the memory address of first element in array
  // cout << &luckyNumbers[0] << endl; // will __purposefully__ print the address of first element in array
  // cout << luckyNumbers[2] << endl; // will actually print the value stored at [2]
  // cout << *(luckyNumbers + 2) << endl; // dereferenced pointer to first element + 2

  for(int i = 0; i < 5; i++) {
    cout << "Number: ";
    cin >> luckyNumbers[i];
  }

    cout << "Lucky numbers: [";
  for (size_t i = 0; i < 5; i++){
    cout << *(luckyNumbers + i) << (i < 4 ? ", " : "");
  }
  cout << "]" <<endl;

  return 0;
}