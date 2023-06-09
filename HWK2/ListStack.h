// the reason for choosing a SLL was because of the one directional nature of a stack, where don't necessarily care about anything
// but the first element we can look at. The idea is basically adding nodes at the first position at all times.
#ifndef SLLIST_H_
#define SLLIST_H_

template<class T>
class ListStack {
    struct Node {
        T _x;
        Node *_next;
    };

	Node *_head;
	Node *_tail;
	int _n;

public:

    // Constructor
    ListStack();

    // Destructor
    ~ListStack();

    // get & set operations (INEFFICIENT - if we are doing frequent 'get' or 'set', use arrays)
    T get(int i);

    void set(int i, T x);

    void push(T x);

    // add 
    void add(int i, T x);

    // remove
    T remove(int i);

    T pop(); // assumes removal from the head -- notice this is NOT just a wrapper for remove(int i), but a completely different implementation
};

template<class T>
ListStack<T>::ListStack() { 
	_n = 0;
	_head = _tail = nullptr;
}

template<class T>
ListStack<T>::~ListStack() {
	Node *u = _head;
	while (u != nullptr) {
		Node *w = u;
		u = u->_next;
		delete w;
	}
}

template<class T>
T ListStack<T>::get(int i) {
    Node *u = new Node;
    u = _head;
    for (int k = 0; k < i; k++) {
        u = u->_next;
    }
    int val = u->_x;
    return val;
}

template<class T>
void ListStack<T>::set(int i, T x) {
    Node *u = new Node;
    u = _head;
    for (int k = 0; k < i; k++) {
        u = u->_next;
    }
    u->_x = x;
}

template<class T>
void ListStack<T>::add(int i, T x) {
    Node *u = new Node;      // new node to be added
    u->_x = x;
    Node* current = _head;      // start at the head 
    int position = 0;           // current position

    // special case where the list is empty
	if (_n == 0) {           // if there is no list, just create the head & tail
		_head = u;
	    _tail = u;  
        _n++;
        return;
    }
    // non-empty list 
    if (i == 0) {    // special case for head pointer
        u->_next = _head;    // points to the old head
        _head = u;          // becomes the new head
    } else {     
        while (current->_next != nullptr) {     // keep going as long as we haven't fallen off the list
            if (position == i) {
                u->_next = current->_next;      // point to the old next thing
                current->_next = u;             // become the new next thing
                break;
            } else {
                current = current->_next;         // move along to the next item
                position++;                     // increase position
            }
        }
    }

    _n++;  // size go up
} 

template<class T>
T ListStack<T>::remove(int i) {
    // special case where the list is empty
	if (_n == 0) {          
		return nullptr;
    }

    // non-empty list 
    Node* current = _head;        // start at the head before we do anything
    int position = 0;             // current position
    
    if (i == 0) {            // special case for removing head pointer 
        _head = _head->_next;     // new head is whatever was next
        T x = current->_x;        // save the value that was there before we destroy it
        delete current;           // get rid of the old head
        return x;        
    } else {     
        while (current->_next != nullptr) {                 // keep going as long as we haven't fallen off the list
            if (position == i-1) {                          // stop BEFORE we get to the place we need to delete
                Node* nextnode = current->_next->_next;         // current->next is the node we need to delete, so grab the thing right after that
                delete current->_next;                          // delete the node at current->next
                current->next = nextnode;                       // set the new next thing 
                break;
            } else {
                current = current->_next;         // move along to the next item
                position++;                     // increase position
            }
        }
    }
}

template<class T>
void ListStack<T>::push(T x) {
	add(0, x);
}

template <class T>
T ListStack<T>::pop() {
    remove(0)
}


#endif /* SLLIST_H_ */