#include <iostream>

using namespace std;

int solve(string& s) {
  int count = 0, size = s.size();

  for(int i = 0; i < size/2; i++) {
    if(s[i] == s[size - i - 1])
      continue;

    if(s[i] < s[size - i - 1])
      s[size - i - 1] = s[i];
    else
      s[i] = s[size - i - 1];
    count++;
  }

  return count;
}

int main() {

  string s = "abracadabra";

  cout << solve(s) << endl;
  cout << s << endl;

  return 0;
}