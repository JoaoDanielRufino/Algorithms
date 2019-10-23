// https://www.geeksforgeeks.org/suffix-array-set-1-introduction/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> buildSuffixArray(string s) {
  vector<string> suffix;

  for(int i = 0; i < s.size(); i++)
    suffix.push_back(s.substr(i, s.size()));

  sort(suffix.begin(), suffix.end());

  return suffix;
}

int main() {

  string s = "banana";

  vector<string> suffix = buildSuffixArray(s);

  for(int i = 0; i < suffix.size(); i++)
    cout << suffix[i] << endl;

  suffix.clear();

  return 0;
}