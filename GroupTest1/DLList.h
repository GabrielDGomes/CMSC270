// NOTE: INITILIZE IS REPRESENTED BY THE CONSTRUCTOR!

template<class T>
class DLList {
    struct Node {
        T _x;
        Node *_next;
        Node *_prev;
    };
    
	Node dummy;
	int _n;

public:

    // these are all "internal" functions
    // things that help the implementation we're trying to accomplish

    // get the node at position i, helpful for other ops
    Node* getNode(int i);

    // adding before a given node
    // the reason this isn't part of a general add function
    // is so that we can keep the inputs to add(i, x) the same
    // and separate out the idea of a 'node' into the implementation
    Node* addBefore(Node *w, T x);

    // remove a specific node, not a specific index 
    void removeNode(Node *w);


    // Constructor
    DLList();

    // Destructor
    ~DLList();
    
    // get & set operations (INEFFICIENT - if we are doing frequent 'get' or 'set', use arrays)
    T get(int i);
    T set(int i, T x);

    // add 
    void add(int i, T x);

    // remove
    void remove(int i);

    // Display Elements in Queue
    void display();
};

template<class T>
DLList<T>::DLList(){
    _n = 0;
    dummy._next = &dummy;
    dummy._prev = &dummy;
}

template<class T>
DLList<T>::~DLList() {
}

template<class T>
typename DLList<T>::Node* DLList<T>::getNode(int i){
    if(i < _n/2){
        Node* finderNode = dummy._next;
        int j = 0;
        while(j < i){
            finderNode = finderNode->_next;
            j++;            
        }
        return finderNode;
    } else {
        Node* finderNode2 = &dummy;
        for(int k = _n; k > i; k--){
            finderNode2 = finderNode2->_prev;
        }
        return finderNode2;
    }
}

template<class T>
typename DLList<T>::Node* DLList<T>::addBefore(Node* referenceNode, T value){
    Node* newNode = new Node;
    newNode->_x = value;
    newNode->_prev = referenceNode->_prev;
    newNode->_next = referenceNode;
    newNode->_next->_prev = newNode;
    newNode->_prev->_next = newNode;
    _n++;
    return newNode;
}

template<class T>
void DLList<T>::removeNode(Node* deleteNode){
    deleteNode->_prev->_next = deleteNode->_next;
    deleteNode->_next->_prev = deleteNode->_prev;
    delete deleteNode;
    _n--;
    }

template<class T>
void DLList<T>::remove(int i){
    removeNode(getNode(i));
}


template<class T>
void DLList<T>::add(int i, T value){
    addBefore(getNode(i), value);
}

template<class T>
T DLList<T>::get(int i){
    return getNode(i)->_x;
}

template<class T>
T DLList<T>::set(int i, T value){
    Node* changeNode;
    changeNode = getNode(i);
    T oldValue = changeNode->_x;
    changeNode->_x = value;
    return oldValue;
}

template<class T>
void DLList<T>::display(){
    // Function to print all the elements of the List
    Node* temp;
    // Check for List underflow
    if (dummy._next->_x == NULL) {
        std::cout << "Double Linked List is Empty!" << std::endl;
        return;
    } else {
        temp = &dummy;
        std::cout << "Dummy <==> ";
        while (temp->_next->_x != NULL) {
            // Print node data
            std::cout << temp->_next->_x;
            // Assign temp link to temp
            temp = temp->_next;
            if (temp != NULL)
                std::cout << " <==> ";
            }
        std::cout << "\n" << std::endl;
        }
}