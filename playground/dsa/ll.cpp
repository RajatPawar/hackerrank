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
    int size();
    void print_list();
    void delete_node_first();
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
int LinkedList<g_datatype> :: size() {
    static Node<g_datatype> *itr = head;
    if((itr = itr->get_next()) == nullptr) return 1;
    else return 1 + LinkedList<g_datatype>::size();
}

template <class g_datatype>
void LinkedList<g_datatype> :: delete_node_first() {
    Node<g_datatype> *itr = this->head;
    head->set_next(head->get_next());
    //delete itr;
}

int main() {

    LinkedList<string> ll;

    ll.add_node("sparta!");
    ll.add_node("is");
    ll.add_node("This");
    ll.add_node("is");
    ll.add_node("This");
    ll.add_node("is");
    ll.add_node("This");
    ll.print_list();
    printf("\nSIZE: %d\n", ll.size());
    //ll.delete_node_first(); 
    printf("\nSIZE: %d\n", ll.size());
    return 0;
}
