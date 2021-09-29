using namespace std;

template <typename T>
class Node;

// pass by ref
template<typename T>
ostream& operator<<(ostream &os, const Node<T>* rhs);

// pass by copy
template<typename T>
ostream& operator<<(ostream &os, const Node<T> rhs);


template <typename T>
class Node {
  public:
    T data;
    int id;
    Node* next;

    // pass by ref
    friend ostream& operator<< <>(ostream& os, const Node* rhs);

    // pass by copy
    friend ostream& operator<< <>(ostream& os, const Node rhs);
};

// pass by ref
template<typename T>
ostream& operator<<(ostream &os, const Node<T>* rhs) {
  os << "{ " << "ID: " << rhs->id << ", data: " << rhs->data << " }";
  return os;
}

// pass by copy
template<typename T>
ostream& operator<<(ostream &os, const Node<T> rhs) {
  os << "{ " << "ID: " << rhs.id << ", data: " << rhs.data << " }";
  return os;
}