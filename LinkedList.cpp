#include <bits/stdc++.h>
#include <string>

using namespace std;

template <typename T>
class Node {
  public:
    T data;
    int id;
    Node* next;
    friend ostream& operator<<(ostream& os, const Node<T>& rhs);
};

template<typename T>
ostream& operator<<(ostream& os, const Node<T>& rhs) {
  os << "{ " << "ID: " << rhs->id << ", data: " << rhs->data << " }";
  return os;
}

template <typename T>
class LinkedList {
  public:
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
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

  if(this->tail == NULL) {
    this->tail = node;
  }

  if(this->head != NULL) {
    node->next = this->head;
  }

  this->head = node;


  this->length++;
  this->head->id = this->length;
}

template<typename T>
void LinkedList<T>::push_back(T dat) {
  Node<T>* node = new Node<T>;
  Node<T>* current = this->head;
  node->data = dat;

  if(this->head == NULL) {
    this->head = node;
  }

  if(this->tail != NULL) {
    this->tail->next = node;
  }

  this->tail = node;
  this->length++;
  this->tail->id = this->length;
}

template<typename T>
void LinkedList<T>::pop_back() {
  if(this->tail == NULL) return;

  Node<T>* current = this->head;
  Node<T>* target = current;

  while(current->next != NULL) {
    target = current;
    current = current->next;
  }

  this->tail = target;
  this->tail->next = NULL;

  this->length--;

  if(this->length == 0) {
    this->head = NULL;
    this->tail = NULL;
  }
}

template<typename T>
void LinkedList<T>::pop_front() {
  if(this->head == NULL) return;

  Node<T>* temp = NULL;

  if(this->head->next != NULL) {
    temp = this->head->next;
  }

  this->head = temp;
  this->length--;

  if(this->length == 0) {
    this->head = NULL;
    this->tail = NULL;
  }
}

int main(int argc, const char** argv) {

  // Node<int> ni;         // int Node
  LinkedList<int> lli;  // int LinkedList
  lli.push_front(123);
  lli.push_front(456);
  lli.push_front(789);
  lli.push_back(112);
  lli.pop_back();
  lli.pop_front();

  LinkedList<string> lls;
  lls.push_front("ABC");


  cout << "Head: " << "{ID: " << lli.head->id << ", data: " << lli.head->data << "}" <<endl;
  cout << "Second: " << "{ID: " << lli.head->next->id << ", data: " << lli.head->next->data << "}" <<endl;
  cout << "Tail: " << "{ID: " << lli.tail->id << ", data: " << lli.tail->data << "}" <<endl;
  cout << lli.tail;
  return 0;
}