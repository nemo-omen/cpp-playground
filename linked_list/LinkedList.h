#include "Node.h"
using namespace std;

template <typename T>
class LinkedList;

// pass by ref - LinkedList
template<typename T>
ostream& operator<<(ostream &os, const LinkedList<T>* rhs);

// pass by copy - LinkedList
template<typename T>
ostream& operator<<(ostream &os, const LinkedList<T> rhs);


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

    // pass by ref
    friend ostream& operator<< <>(ostream& os, const LinkedList* rhs);

    // pass by copy
    friend ostream& operator<< <>(ostream& os, const LinkedList rhs);
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

// pass by ref
template<typename T>
ostream& operator<<(ostream &os, const LinkedList<T>* rhs) {
  os << "[";

  if(rhs->length > 0) {
    Node<T>* current = rhs->head;
    while(current->next != NULL) {
      os << current << ", ";
      current = current->next;
    }
    os << current;
  }

  os <<  "]" << endl;
  return os;
}

// pass by copy
template<typename T>
ostream& operator<<(ostream &os, const LinkedList<T> rhs) {
  os << "[";

  if(rhs.length > 0) {
    Node<T>* current = rhs.head;
    while(current->next != NULL) {
      os << current << ", ";
      current = current->next;
    }
    os << current;
  }
  
  os << "]" << endl;
  return os;
}