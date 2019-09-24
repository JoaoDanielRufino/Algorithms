// Generate all combinations of valid parentheses
#include <iostream>

using namespace std;

void solve(string res, int open, int close, int size) {
  if(res.size() == size * 2) {
    cout << res << endl;
    return;
  }

  if(open < size)
    solve(res + "(", open + 1, close, size);
  if(close < open)
    solve(res + ")", open, close + 1, size);
}

int main() {

  int n = 4;

  solve("", 0, 0, n);


  return 0;
}