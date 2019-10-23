#include <iostream>

using namespace std;

struct ListNode {
  int data;
  ListNode *next;
};

class List {
  private:
    int size;
    ListNode *head, *tail;

  public:
    List() {
      size = 0;
      head = nullptr;
      tail = nullptr;
    }

    void push_back(int val) {
      ListNode *tmp = new ListNode();
      tmp->data = val;
      tmp->next = nullptr;

      if(!head) {
        head = tmp;
        tail = tmp;
      }
      else {
        tail->next = tmp;
        tail = tmp;
      }

      size++;
    }

    void delete_front() {
      if(!size)
        return;

      if(size == 1) {
        head = nullptr;
        tail = nullptr;
      }
      else {
        ListNode *tmp = new ListNode();
        tmp = head;
        head = head->next;
        delete tmp;
      }

      size--;
    }

    void delete_last() {
      if(!size)
        return;

      if(size == 1) {
        head = nullptr;
        tail = nullptr;
      }
      else {
        ListNode *prev = new ListNode();
        ListNode *curr = new ListNode();

        curr = head;
        while(curr->next) {
          prev = curr;
          curr = curr->next;
        }
        tail = prev;
        prev->next = nullptr;
        delete curr;
      }

      size--;
    }

    void delete_position(int pos) { // 0 - (size-1)
      if(pos >= size)
        return;

      if(size == 1) {
        head = nullptr;
        tail = nullptr;
      }
      else if(!pos) {
        head = head->next;
      }
      else {
        ListNode *prev = new ListNode();
        ListNode *curr = new ListNode();

        curr = head;
        for(int i = 0; i < pos; i++) {
          prev = curr;
          curr = curr->next;
        }
        prev->next = curr->next;

        if(pos == size-1)
          tail = prev;

        delete curr;
      }

      size--;
    }

    void print_list() {
      ListNode *tmp = new ListNode();
      tmp = head;

      while(tmp) {
        cout << tmp->data << " ";
        tmp = tmp->next;
      }

      cout << endl;
    }
};

int main() {

  List l;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);

  l.print_list();

  //l.delete_front();
  //l.delete_last();
  l.delete_position(0);

  l.push_back(7);
  l.push_back(8);

  l.print_list();

  return 0;
}