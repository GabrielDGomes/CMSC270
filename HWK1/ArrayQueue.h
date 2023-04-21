
#include "utils.h"

template<class T>
class ArrayQueue{
    protected:
        int _n;
        int _j;
        T *_a;
        int _size;
        void resize();  // readjusts array size(expands or shrinks)
    public:
        //constructor
        ArrayQueue(int n);

        // Destructor
        ~ArrayQueue();

        // adds as the last element of the queue
        bool add(T x);

        // Removes first element in queue
        T remove();

        // returns array size
        int getSize();
};

template<class T>
ArrayQueue<T>::ArrayQueue(int n) {
    _a = new T[n];
    _size = sizeof(_a) / sizeof(int);
    _n = 0;
    _j = 0;
}

template<class T>
ArrayQueue<T>::~ArrayQueue() {}

template<class T>
bool ArrayQueue<T>::add(T x){
    if (_n + 1 > getSize()){
        resize();
    }
    a[(_j + _n) % getSize()] = x;
    _n++;
    return true;
}

template<class T>
T ArrayQueue<T>::remove(){
    x = _a[_j]
    _j = (_j + 1) % getSize();
    _n--;
    if(getSize() > 3*_n){
        resize();
    }
    return x;
}

template<class T>
void ArrayQueue<T>::resize(){
    b = ArrayQueue(max(1, 2*_n))
    for (int k = 0; k < _n; k++){
        b[k] = a[(_j+k) % getSize()]
    }
    _a = b;
    _j = 0;
}

template<class T>
int ArrayQueue<T>::getSize() {
    return _size;
}