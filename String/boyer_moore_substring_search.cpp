// https://www.coursera.org/learn/algorithms-part2/lecture/CYxOT/boyer-moore

#include <iostream>
#include <vector>
#include <algorithm>

#define CHAR_SIZE 26

using namespace std;

vector<int> skipArray(string pattern) {
  vector<int> vet(CHAR_SIZE, -1);

  for(int i = 0; i < pattern.size(); i++)
    vet[pattern[i]] = i;

  return vet;
}

int boyerMoore(string str, string pattern) {
  int n = str.size();
  int m = pattern.size();
  int skip;
  vector<int> aux = skipArray(pattern);

  for(int i = 0; i <= n-m; i += skip) {
    skip = 0;
    for(int j = m-1; j >= 0; j--) {
      if(pattern[j] != str[i+j]) {
        skip = max(1, j - aux[str[i+j]]);
        break;
      }
    }
    if(!skip)
      return i;
  }

  return -1;
}

int main() {

  string str = "ABACADABRAC";
  string pattern = "ABRA";

  cout << boyerMoore(str, pattern) << endl;

  return 0;
}