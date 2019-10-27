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

    void printTrie(Node *root, string current) {
      if(!root)
        return;

      if(root->isEndOfWord)
        cout << current << endl;

      for(int i = 0; i < CHAR; i++) {
        current.push_back('a' + i);
        printTrie(root->next[i], current);
        current.pop_back(); // Backtraking
      }
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

    bool search(string key) {
      Node *tmp = root;
      for(int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';
        if(!tmp->next[index])
          return false;
        tmp = tmp->next[index];
      }

      return tmp->isEndOfWord;
    }

    void printAutoSuggestions(string query) {
      Node *tmp = root;

      // Finding the last level of the prefix
      for(int i = 0; i < query.size(); i++) {
        int index = query[i] - 'a';
        if(!tmp->next[index]) {
          cout << "Prefix not found" << endl;
          return;
        }
        tmp = tmp->next[index];
      }

      printTrie(tmp, query);
    }

    void printSorted() {
      printTrie(root, "");
    }
};

int main() {

  Trie trie;

  trie.insert("hello");
  trie.insert("word");
  trie.insert("hey");
  trie.insert("help");
  trie.insert("the");
  trie.insert("bye");
  trie.insert("hell");
  trie.insert("all");
  trie.insert("abyss");
  trie.insert("alone");

  trie.search("hey") ? cout << "True\n" : cout << "False\n";
  trie.search("hel") ? cout << "True\n" : cout << "False\n";
  trie.search("word") ? cout << "True\n" : cout << "False\n";
  trie.search("happy") ? cout << "True\n" : cout << "False\n";

  cout << endl;

  cout << "Auto suggestions:" << endl;
  trie.printAutoSuggestions("he");

  cout << endl << "Words sorted:" << endl;
  trie.printSorted();

  return 0;
}