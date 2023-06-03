#include "utils.h"

template<class T>
class ArrayDeque{
    protected:
        protected:
        int _n; 
        int _j;
        T *_a;
        int _size;
        void resize();
    public:
        ArrayDeque(int n);

        ~ArrayDeque();

        T get(int i);
        
        T set(int i, T x);

        void add(int i, T x);
        void add(T x) { add(size(), x); }

        T remove(int i);

        int getSize();
};

template<class T>
ArrayDeque<T>::ArrayDeque(int n){
    _a = new T[n];
    _size = sizeof(_a) / sizeof(int);
    _j = 0;
    _n = 0;
}

template<class T>
ArrayDeque<T>::~ArrayDeque() {}

template<class T>
T ArrayDeque<T>::get(int i){
    return _a[(i + _j)%getSize()];
}

template<class T>
T ArrayDeque<T>::set(int i, T x){
    y = _a[(i + _j)%getSize()];
    _a[(i + _j)%getSize()] = x;
    return y;
}

template<class T>
void ArrayDeque<T>::add(int i, T x){
    if(_n = getSize()){
        resize();
    }
    if(i<(_n/2)){
        _j = (_j - 1) % getSize();
        for (int k = 0; k < i; k++){
            _a[(_j + k) % getSize()] = _a[(_j + k + 1) % getSize()]
        }
    }
    else{
        for (int k = _n; k >= i+1; k--){
            _a[(_j + k) % getSize()] = _a[(_j + k - 1) % getSize()]
        }
    }
    _a[(_j + i) % getSize()] = x;
    n++;
}

template<class T>
T ArrayDeque<T>::remove(int i){
    x = _a[(_j+i)%getSize()];

    if(i < (_n/2)){
        for (int k = i; k > 0; k--){
            _a[(_j + k)%getSize()] = a[(_j + k - 1)%getSize()]
        }
        _j = (_j+1)%getSize()
    }
    else{
        for (int k = i; k < n-3; k++){
            a[(_j+k)%getSize()] = a[(_j + k + 1)%getSize()]
        }
    }
    _n--;
    if(getSize() > 3*_n){
        resize();
    }

    return x;
}

template<class T>
void ArrayDeque<T>::resize(){
    b = ArrayQueue(max(1, 2*_n))
    for (int k = 0; k < _n; k++){
        b[k] = a[(_j+k) % getSize()]
    }
    _a = b;
    _j = 0;
}

template<class T>
int ArrayDeque<T>::getSize() {
    return _size;
}
