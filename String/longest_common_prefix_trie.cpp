// https://www.geeksforgeeks.org/longest-common-prefix-using-trie/

#include <iostream>

#define CHAR 26

using namespace std;

struct Node {
    Node *next[CHAR];
    bool isEndOfWord;

    Node() {
      for(int i = 0; i < CHAR; i++)
        next[i] = nullptr;
      isEndOfWord = false;
    }
};

class Trie {
  private:
    Node *root;

    bool hasOneChild(Node *root, int &index) {
      int count = 0;

      for(int i = 0; i < CHAR; i++) {
        if(root->next[i]) {
          index = i;
          count++;
        }
        if(count > 1)
          return false;
      }

      return count == 1;
    }

  public:
    Trie() {
      root = new Node();
    }

    void insert(string key) {
      Node *tmp = root;

      for(int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if(!tmp->next[index])
          tmp->next[index] = new Node();
        tmp = tmp->next[index];
      }

      tmp->isEndOfWord = true;
    }

    string longestCommonPrefix() {
      Node *tmp = root;
      string prefix;
      int index;

      while(hasOneChild(tmp, index) && !tmp->isEndOfWord) {
        prefix.push_back('a' + index);
        tmp = tmp->next[index];
      }

      return prefix;
    }
};

int main() {

  Trie trie;

  trie.insert("flower");
  trie.insert("flowerser");
  trie.insert("flight");

  cout << trie.longestCommonPrefix() << endl;

  return 0;
}