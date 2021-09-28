#include <bits/stdc++.h>
#include <string>

using namespace std;

template <typename T>
class Node {
  public:
    T data;
    int id;
    Node* next;
};

template <typename T>
class LinkedList {
  public:
    Node<T>* head;
    Node<T>* tail;
    int length = 0;
    void push_front(T dat);
    void push_back(T dat);
    void pop_front();
    void pop_back();
};

template <typename T>
void LinkedList<T>::push_front(T dat) {
  Node<T>* node = new Node<T>;
  node->data = dat;

  if(this->length == 1) {
    this->tail = this->head;
    this->head = node;
    this->head->next = this->tail;
  } else {
    node->next = this->head;
    this->head = node;
  }

  this->length++;
  this->head->id = this->length;
}

// template<typename T>
// void LinkedList<T>::push_back(T dat) {
//   Node<T>* node = new Node<T>;
//   Node<T>* current = this->head;

//   node->data = dat;

//   for(int i = 0; i < this->length; i++) {
//     if(current->next) {
//       current = current->next;
//     } else {
//       current->next = node;
//       this->tail = current->next;
//       this->length++;
//       this->tail->id = this->length;
//     }
//   }
// }

int main(int argc, const char** argv) {

  // Node<int> ni;         // int Node
  LinkedList<int> lli;  // int LinkedList
  lli.push_front(123);
  lli.push_front(456);
  lli.push_front(789);
  // lli.push_back(789);


  LinkedList<string> lls;
  lls.push_front("ABC");


  cout << "Head: " << "{ID: " << lli.head->id << ", data: " << lli.head->data << "}" <<endl;
  cout << "Second: " << "{ID: " << lli.head->next->id << ", data: " << lli.head->next->data << "}" <<endl;
  cout << "Tail: " << "{ID: " << lli.tail->id << ", data: " << lli.tail->data << "}" <<endl;
  // cout << "First: " << "{ID: " << lls.head->id << ", data: " << lls.head->data << "}" <<endl;
  return 0;
}