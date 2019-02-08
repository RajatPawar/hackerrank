#include <iostream>

using namespace std;

template <class g_datatype>
class Node {
    
    g_datatype data;
    Node *next;

    public:

    Node(g_datatype data) : data(data), next(nullptr) {};
    ~Node() {}

    Node* get_next();
    void set_next(Node*);
    g_datatype get_data();
    void set_data(g_datatype);
};

template <class g_datatype>
class LinkedList {
    
    Node<g_datatype> *head;
    
    public:

    LinkedList() : head(nullptr) {};
    ~LinkedList() {}

    void add_node(g_datatype);
    Node<g_datatype>* find_node(g_datatype);
    void print_list();
    void delete_node(g_datatype);
    bool compare(LinkedList<char> *ll);
};

template <class g_datatype>
Node<g_datatype>* Node<g_datatype> :: get_next() {
    return next;
}

template <class g_datatype>
void Node<g_datatype> :: set_next(Node<g_datatype>* node) {
    next = node;
}

template <class g_datatype>
g_datatype Node<g_datatype> :: get_data() {
    return this->data;
}

template <class g_datatype>
void Node<g_datatype> :: set_data(g_datatype data) {
    this->data = data;
}

template <class g_datatype>
void LinkedList<g_datatype> :: add_node(g_datatype data) {
    Node<g_datatype> *temp;
    temp = new Node<g_datatype>(data);
    
    if(head) 
        temp->set_next(head);
    
    head = temp;
}

template <class g_datatype>
void LinkedList<g_datatype> :: print_list() {
    cout<<endl;
    Node<g_datatype> *itr = head;

    while(itr) {
        cout<<itr->get_data()<<" ";
        itr = itr->get_next();
    }
}

template <class g_datatype>
bool LinkedList<g_datatype> :: compare(LinkedList<char> *ll) {
    Node<g_datatype> *itr_one = this->head, *itr_two = ll->head;
    while(itr_one && itr_two) {
       if(*itr_one != *itr_two) return false;
       itr_one = this->get_next();
       itr_two = itr_two->get_next();
    }
    return ((itr_one == itr_two) == nullptr) ? true : false;
}

int main() {

    LinkedList<char> ll, ll_two;
    ll.add_node('a');
    ll.add_node('b');
    ll.add_node('c');
    ll.add_node('z');

    ll_two.add_node('a');
    printf("\nOP: %d\n", ll.compare(&ll_two));
    
    return 0;
}
