// Complexity: O(n * m), n = number of strings, m = length of the largest string

#include <iostream>
#include <vector>

using namespace std;

string lcp(string s, string p) {
  int i, j;
  string prefix;

  i = j = 0;
  while(i < s.size() && j < p.size() && s[i] == p[i]) {
    prefix += s[i];
    i++;
    j++;
  }

  return prefix;
}

string longestCommonPrefix(vector<string> vet) {
  string longestPrefix = vet[0];

  for(int i = 1; i < vet.size(); i++) {
    longestPrefix = lcp(longestPrefix, vet[i]);
  }

  return longestPrefix;
}

int main() {

  vector<string> vet;

  vet.push_back("flower");
  vet.push_back("flow");
  vet.push_back("flight");

  cout << longestCommonPrefix(vet) << endl;

  return 0;
}