// https://www.youtube.com/watch?v=GTJr8OvyEVQ

#include <iostream>
#include <vector>

using namespace std;

vector<int> computeLogestPrefixSufix(string pattern) {
  int i = 1, index = 0;
  vector<int> lps(pattern.size(), 0);

  while(i < pattern.size()) {
    if(pattern[i] == pattern[index])
      lps[i++] = ++index;
    else {
      if(index != 0)
        index = lps[index - 1];
      else
        lps[i++] = 0;
    }
  }

  return lps;
}

int kmpSearch(string str, string pattern) {
  int i = 0, j = 0;
  vector<int> lps = computeLogestPrefixSufix(pattern);

  while(i < str.size() && j < pattern.size()) {
    if(str[i] == pattern[j]) {
      i++;
      j++;
    }
    else {
      if(j != 0)
        j = lps[j - 1];
      else
        i++;
    }
  }

  if(j == pattern.size())
    return i - j;
  return -1;
}

int main() {

  string str = "ABACADABRAC";
  string pattern = "ABRA";

  cout << kmpSearch(str, pattern) << endl;

  return 0;
}