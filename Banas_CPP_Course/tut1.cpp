#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
  cout << "Hello, world!" << '\n';

  if(argc != 1) {
    cout << "Entered " << argc << " arguments \n";

    for(int i = 0; i < argc; i++) {
      cout << argv[i] << '\n';
    }
  }

  return 0;
}