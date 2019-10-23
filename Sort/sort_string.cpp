// Complexity: O(n)

#include <iostream>

using namespace std;

void sortString(string &s) {
  int *count = new int[26]; // 26 chars a - z;

  for(int i = 0; i < s.size(); i++) {
    count[s[i] - 'a']++;
  }

  int j = 0;
  for(char i = 'a'; i <= 'z'; i++) {
    while(count[i - 'a']--) {
      s[j++] = i;
    }
  }
}

int main() {

  string s = "banana";

  sortString(s);

  cout << s << endl;

  return 0;
}