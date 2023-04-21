#include "utils.h"

template<class T>               // Allows this data structure to use any given type as long as it fits the operations
class ArrayStack {
    protected:                  // Can only be accessed by 'friend' classes; will see more about this soon 
        int _n;                // The underscores are convention to show these are member variables for the class
        T *_a;
        int _size;               // total size of array, NOT number of elements
        void resize();
    public:
        // Constructor
        ArrayStack(int n);

        // Destructor
        ~ArrayStack();

        // Get & Set operations
        T get(int i);
        T set(int i, T x);

        // Add at specified place, add at top of stack
        void add(int i, T x);
        void add(T x) { add(size(), x); }

        // Remove at specified place 
        T remove(int i);
        
        // push and pop operations for stack-like behavior 
        void push(T x);
        T pop();

        // Empty the stack 
        void clear();

        // --- Below this point are some helpful functions ---
        // not necessary parts of the data structure, but helpful for working with the class
        int getSize();
        void display();
};

//  Constructor and Destructor
//      for the constructor, we initialize a new array as the "backing array"
//      these constructors/destructors can be identical for any array-based implementation
template<class T>
ArrayStack<T>::ArrayStack(int n) {
    _a = new T[n];
    _size = sizeof(_a) / sizeof(int) // For more information, see https://www.w3schools.com/cpp/cpp_arrays_size.asp
}

template<class T>
ArrayStack<T>::~ArrayStack() {}

// resize operation creates a new array twice the size of the original (or length 1 if the original array is empty)
// book: 2.1.2
template<class T>
void ArrayStack<T>::resize() {
    b = T[max(1, 2*_n)]
    for (int i = 0; i < _n; i++) {
        b[i] = _a[i]
    }     
    _a = b;
    _size = sizeof(_a) / sizeof(int);
}

// get & set operations
// book: 2.1.1
template<class T>
T ArrayStack<T>::get(int i) {
    return _a[i];
}

template<class T>
T ArrayStack<T>::set(int i, T x) {
    T y = _a[i];
    _a[i] = x;
    return y;
}

// add operation
// book: 2.1.1
template<class T>
void ArrayStack<T>::add(int i, T x) {
    // resize if array is too small to fit 
    if (_n + 1 > _size) {
        resize();
    }
    // shift all elements of the array that were to the right of index i one space to the right to make room for the new element
    for (int j = n; j > i; j--) {
        _a[j] = _a[j-1];
    }
    // insert the new element 
    _a[i] = x;
    // increase the array element count
    _n++;
}

// remove operation
// book: 2.1.1 
template<class T>
T ArrayStack<T>::remove(int i) {
    // get the original element at the index being removed
    T x = _a[i];
    // shift all elements of the array that are to the right of index i one space to the left to overwrite the original element
    for (int j = i; j < _n - 1; j++) {
        _a[j] = _a[j+1];
    }
    // decrease the array element count
    _n--;
    // resize if array is too large for the data 
    if (_size >= 3 * _n) {
        resize();
    }
    // original element in case we want it
    return x;
}

// push and pop wrappers for stack-like functionality
// notice how these do not rewrite the add and remove functions, but merely call these general functions for a specific case
// See pg 37 for additional explanation
template<class T>
void ArrayStack<T>::push(T x) {
    add(_n, x);
}

template<class T>
T ArrayStack<T>::pop() {
    return remove(_n - 1);
}


// --- Little helper functions --- 
template<class T>
int ArrayStack<T>::getSize() {
    return _size;
}

template<class T>
void ArrayStack<T>::display() {
    std::cout << "[";
    for (int i = 0; i < _n; i++) {
        std::cout << " " << i;
    }
    for (int j = _n; j < _size; j++) {
        std::cout << " -";
    }
    std::cout << " ]" << std::endl;
}