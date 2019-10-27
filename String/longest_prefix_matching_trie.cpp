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

    string longestPrefix(string query) {
      Node *tmp = root;
      string prefix;
      int maxLen = 0;

      for(int i = 0; i < query.size(); i++) {
        int index = query[i] - 'a';
        if(tmp->next[index]) {
          prefix += query[i];
          if(tmp->isEndOfWord)
            maxLen = i+1;
          tmp = tmp->next[index];
        }
        else
          break;
      }

      if(tmp->isEndOfWord)
        return prefix;
      return prefix.substr(0, maxLen);
    }    
};

int main() {

  Trie trie;

  trie.insert("univer");
  trie.insert("birth");
  trie.insert("birthd");
  trie.insert("base");
  trie.insert("comp");

  cout << trie.longestPrefix("birthday") << endl;

  return 0;
}