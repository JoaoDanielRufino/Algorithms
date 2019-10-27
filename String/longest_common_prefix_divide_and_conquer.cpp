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

string longestCommonPrefix(vector<string> vet, int l, int r) {
  if(l == r)
    return vet[l];

  int mid = l + (r - l) / 2;
  string s = longestCommonPrefix(vet, l, mid);
  string p = longestCommonPrefix(vet, mid+1, r);
  return lcp(s, p);
}

int main() {

  vector<string> vet;

  vet.push_back("flower");
  vet.push_back("flow");
  vet.push_back("flight");

  cout << longestCommonPrefix(vet, 0, vet.size()-1) << endl;

  return 0;
}