// Comprexity: O(n^2logn)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefix(string s, string p) {
  int len = min(s.size(), p.size());
  
  for(int i = 0; i < len; i++) {
    if(s[i] != p[i])
      return s.substr(0, i);
  }

  return s.substr(0, len);
}

string longestRepeatedSubstring(string s) {
  vector<string> suffix;

  for(int i = 0; i < s.size(); i++)
    suffix.push_back(s.substr(i, s.size())); // Building the suffix array

  sort(suffix.begin(), suffix.end());

  string lrs;
  for(int i = 0; i < s.size()-1; i++) {
    string len = longestCommonPrefix(suffix[i], suffix[i+1]);
    if(len.size() > lrs.size())
      lrs = len;
  }

  return lrs;
}

int main() {

  string s = "abracadrabra";
  string p = "banana";

  cout << longestRepeatedSubstring(s) << endl;

  cout << longestRepeatedSubstring(p) << endl;

  return 0;
}