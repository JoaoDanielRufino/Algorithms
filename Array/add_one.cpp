// Input: [1, 9, 9] -> output: [2, 0, 0, 0]

#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &vet) {
  int i = vet.size() - 1;
  
  if(vet[i] < 9) {
    vet[i]++;
    return;
  }
  else {
    while(i > 0 && vet[i] == 9) {
      vet[i] = 0;
      if(vet[i-1] < 9) {
        vet[i-1]++;
        return;
      }
      i--;
    }

    vet.insert(vet.begin(), 1); // [9, 9] -> [1, 0, 0]
    vet[1] = 0;
  }
}

int main() {

  int n, a;
  vector<int> vet;

  while(cin >> n) {
    while(n--) {
      cin >> a;
      vet.push_back(a);
    }

    solve(vet);

    for(int i = 0; i < vet.size(); i++) {
      cout << vet[i] << " ";
    }

    cout << endl;
    vet.clear();
  }

  return 0;
}