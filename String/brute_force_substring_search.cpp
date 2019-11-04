#include <iostream>

using namespace std;

int substring_search(string str, string pattern) {
  int n = str.size();
  int m = pattern.size();

  for(int i = 0; i <= n - m; i++) {
    int j;
    for(j = 0; j < m; j++) {
      if(str[i+j] != pattern[j])
        break;
    }
    if(j == m)
      return i;
  }
  
  return -1;
}

int main() {

  string str = "ABACADABRAC";
  string pattern = "ABRA";

  cout << substring_search(str, pattern) << endl;

  return 0;
}