#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

void decToBin(uint dec);

template<typename T>
void printArray(const T * array, int count);

template<typename T>
void mySwap(T& first, T& second);

template<typename T>
void bubbleSort(T *array, int n);

int main(int argc, const char** argv) {
    // decToBin(25);

    // int a[4] = {5, 10, 15, 20};
    // printArray(a, 4);

    const int aCount = 5, bCount = 7, cCount = 5, dCount = 8;
    int a[aCount] = {5, 4, 3, 2, 1};
    double b[bCount] = {7.7, 6.6, 5.5, 4.4, 3.3, 2.2, 1.1};
    char c[cCount] = {'H', 'E', 'L', 'L', 'O'};
    string d[dCount] = {"Cadillac", "Oldsmobile", "Chevrolet",
                      "Toyota", "Lexus", "Dodge", "GMC", "BMW"};

    cout << "Array a contains:" << endl;
    printArray(a, aCount);      // integer print function template
    bubbleSort(a, aCount);      // integer sort function template
    printArray(a, aCount);      // integer print function template

    cout << "Array b contains:" << endl;
    printArray(b, bCount);      // double print function template
    bubbleSort(b, bCount);      // double sort function template
    printArray(b, bCount);      // double print function template

    cout << "Array c contains:" << endl;
    printArray(c, cCount);      // character print function template
    bubbleSort(c, cCount);      // character sort function template
    printArray(c, cCount);      // character print function template

    cout << "Array d contains:" << endl;
    printArray(d, dCount);      // string print function template
    bubbleSort(d, dCount);      // string sort function template
    printArray(d, dCount);      // string print function template
    return 0;
}

template<typename T>
void mySwap(T& first, T& second) {
  T temp;

  temp = first;
  first = second;
  second = temp;
}

// replace the __outer loop__ with the recursive version
template<typename T>
void bubbleSort(T *array, int n) {
  if(n <= 1) {
    return;
  } else {
    for(int i = 0; i < (n - 1); ++i) {
      if(array[i] > array[i + 1]) {
        mySwap(array[i], array[i + 1]);
      }
    }
    bubbleSort(array, n - 1);
  }
}

void decToBin(uint dec) {
  string s;
  static vector<string> v;
  v.push_back(to_string(dec % 2));
  if(dec / 2 > 0) {
    decToBin(dec / 2);
  } else {
    reverse(v.begin(), v.end());
    for(const auto &letter : v) s += letter;
    stringstream ss(s);
    cout << ss.str() << endl;
  }
}

template<typename T>
void printArray(const T * array, int count) {
  if(count <= 0) {
    cout << endl;
  } else {
    cout << *array << " ";
    printArray(array + 1, count - 1);
  }
}