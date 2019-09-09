// O(n*n!), n! permutations, and O(n) to print all strings

#include <iostream>

using namespace std;

void permute(string str, int k) {
  if(k == str.size())
    cout << str << endl;

  for(int i = k; i < str.size(); i++) {
    swap(str[k], str[i]);
    permute(str, k+1);
    swap(str[k], str[i]); // Backtrack
  }
}

int main() {

  ios::sync_with_stdio(false); //cin.tie(0);
  string str;

  cin >> str;

  permute(str, 0);

  return 0;
}