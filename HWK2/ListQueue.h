// the reason for choosing a DLL was because of its two way nature, where in a queue we add in one side, and remove from the other
// at all times, so by being able to quickly jump to the end of the list is very beneficial compared to a SLL

#ifndef ListQueue_H_                 

template<class T>
class ListQueue {
    struct Node {
        T _x;
        Node *_next;
        Node *_prev;
    };

	Node dummy;
	int _n;

protected:
    Node* getNode(int i);

    Node* addBefore(Node *w, T x);

    void removeNode(Node *w);

public:

    ListQueue();

    ~ListQueue();

    T get(int i);

    T set(int i, T x);

    // add 
    void add(int i, T x);

    // remove
    T remove(int i);

    void display();

    void enqueue(T x);

    void dequeue();
};

template <class T>
ListQueue<T>::ListQueue() {
	_n = 0;
    dummy = new Node;
    dummy._next = &dummy;
    dummy._prev = &dummy;
}

template <class T>
ListQueue<T>::~ListQueue(){
    Node *u = dummy;
	while (u->_next != nullptr) {
		Node *w = u;
		u = u->_next;
		delete w;
	}
}


template <class T>
typename ListQueue<T>::Node* ListQueue<T>::addBefore(Node *w, T x) {
    Node *u = new Node;       
    u->_x = x;
    u->_prev = w->_prev;         
    u->_next = w;                
    u->_next->_prev = u;         
    u->_prev->_next = u;         
    _n++;
    return u;                   
}

template <class T>
typename ListQueue<T>::Node* ListQueue<T>::getNode(int i) {
    Node* p;           
    if (i < _n/2) {
        p = dummy._next;                
        for (int j = 0; j < i; j++) {
            p = p->_next;          
        }
    } else {
        p = &dummy;            
        for (int j = _n; j > i; j--) {
            p = p->_prev; 
        }
    }
    return p;                  
}

template<class T>
void ListQueue<T>::removeNode(Node *w) {
	w->_prev->_next = w->_next; 
	w->_next->_prev = w->_prev;
	_n--;
    delete w;
}

template<class T>
T ListQueue<T>::get(int i) {
    return getNode(i)->_x;
}

template<class T>
T ListQueue<T>::set(int i, T x) {
	Node* u = getNode(i);
	T y = u->_x;
	u->_x = x;
	return y;
}

template<class T>
void ListQueue<T>::add(int i, T x) {
    addBefore(getNode(i), x);
}

template<class T>
T ListQueue<T>::remove(int i) {
	Node *w = getNode(i);
	T x = w->_x;
	removeNode(w);
	return x;
}

template<class T>
void ListQueue<T>::enqueue(T x) {
    add(0, x);
}

template<class T>
void ListQueue<T>::dequeue() {
    remove(_n);
}

template<class T>
void ListQueue<T>::display() {
    for (int i = 0; i < _n; i++) {
        std::cout << get(i) << " ";
    }
    std::cout << std::endl;
}


#endif /*ListQueue_H_*/