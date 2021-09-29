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
    Node<T>* find(T dat);
    // Node<T>* find(int id);
    void push_front(T dat);
    void push_back(T dat);
    void insert(T dat, int index);
    void insertBefore(T dat, int index);
    void insertAfter(T dat, int index);
    void pop_front();
    void pop_back();

    // pass by ref
    friend ostream& operator<< <>(ostream& os, const LinkedList* rhs);

    // pass by copy
    friend ostream& operator<< <>(ostream& os, const LinkedList rhs);
};

template<typename T>
Node<T>* LinkedList<T>::find(T dat) {
  Node<T>* current = this->head;
  Node<T>* target;
  Node<T>* nullTarget;
  for(current = this->head; current != NULL; current = current->next) {
    if(current->data == dat) {
      target = current;
    }
  }

  if(target != NULL) {
    return target;
  } else {
    nullTarget->data = NULL;
    nullTarget->id = NULL;
    return nullTarget;
  }
}

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
void LinkedList<T>::insert(T dat, int index) {
  if(index < 0 || index > this->length) return;
  if(index == this->length) this->push_back(dat);
  if(index == 0) this->push_front(dat);

  Node<T>* node = new Node<T>;
  Node<T>* current = this->head;

  node->data = dat;
  node->id = this->length + 1;

  for(int i = 0; i < index - 1; i++) {
    current = current->next;
  }

  node->next = current->next;
  current->next = node;
  this->length++;
}

template<typename T>
void LinkedList<T>::insertBefore(T dat, int index) {
  if(index <= 0 || index > this->length) return;
  if(index == this->length) this->push_back(dat);
  if(index == 1) {
    this->push_front(dat);
  } else {
    Node<T>* node = new Node<T>;
    Node<T>* current = this->head;

    node->data = dat;
    node->id = this->length + 1;

    for(int i = 0; i < index - 2; i++) {
      current = current->next;
    }

    node->next = current->next;
    current->next = node;
    this->length++;
  }
}

template<typename T>
void LinkedList<T>::insertAfter(T dat, int index) {
  if(index < 0 || index > this->length) return;
  if(index == this->length) this->push_back(dat);

  Node<T>* node = new Node<T>;
  Node<T>* current = this->head;

  node->data = dat;
  node->id = this->length + 1;

  for(int i = 0; i < index; i++) {
    current = current->next;
  }

  node->next = current->next;
  current->next = node;
  this->length++;
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