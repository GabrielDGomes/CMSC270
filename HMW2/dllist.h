
template<class T>
class DLList{
    struct Node {
        T _x;
        Node *_next;
        Node *_prev;
        Node(int x) {
            _x = x;
            _next = nullptr;
            _prev = nullptr;
        }
    };

    Node *_head;
	Node *_tail;
	int _n;

    public:
        //constructor
        DLList();

        // Destructor
        ~DLList();

        Node* get_node(int i);

        // gets ith element in the list
        T get(int i);

        // sets ith element to be x
        T set(int i, T x);

        // ????
        Node* add_before(Node w, T x);

        //
        void add(int i, T x);

        //
        void remove(Node w);
        void remove(int i);

        //
        void remove(int i);
};

template<class T>
DLList<T>::DLList(){
    _n = 0;
    Node dummy = new Node(nil);
    dummy->_next = dummy;
    dummy->_prev = dummy;
}

template<class T>
DLList<T>::~DLList() {
	Node *u = dummy->_next;
	while (u != nullptr) {
		Node *w = u;
		u = u->_next;
		delete w;
	}
}

template<class T>
typename DLList<T>::Node* DLList<T>::get_node(int i){
    Node *p;
    if(i<(n/2)){
        p = dummy->_next
        for (int k = 0; k < i; i++){
            p = p->_next;
        }
    }
    else {
        p = dummy;
        for (int k = 0; k < n-i; i++){
            p = p->_prev
        }
    }
    return p;
}

template<class T>
T DLList<T>::get(int i){
    return get_node(i)->_x;
}

template<class T>
T DLList<T>::set(int i, T x){
    Node u = get_node(i);
    T y = u->_x;
    u->_x = x;
    return y;
}

template<class T>
typename DLList<T>::Node* DLList<T>::add_before(Node w, T x){
    Node u = new Node(x);
    u->_prev = w->_prev;
    u->next = w;
    u->_next->_prev = u;
    u->_prev->_next = u;
    n++;
    return u;
}

template<class T>
void DLList<T>::add(int i, T x){
    add_before(get_node(i), x);
}

template<class T>
void DLList<T>::remove(Node w){
    w->_prev->_next = w->_next;
    w->_next->_prev = w->_prev;
    n--;
    delete w;
}

template<class T>
void DLList<T>::remove(int i){
    remove(get_node(i));
}

