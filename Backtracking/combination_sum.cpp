// This program prints all the combinations to the given sum

#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> numbers, vector<int> current, int target) {
  if(target < 0)
    return;

  if(target == 0) {
    for(int i = 0; i < current.size(); i++)
      cout << current[i] << " ";
    cout << endl;
    return;
  }

  for(int i = 0; i < numbers.size(); i++) {
    current.push_back(numbers[i]);
    solve(numbers, current, target - numbers[i]);
    current.pop_back();
  }
}

int main() {


  int target = 7;
  vector<int> numbers;

  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_back(6);
  numbers.push_back(7);

  vector<int> vet;

  solve(numbers, vet, target);

  return 0;
}