#pragma once
#include <iostream>
#include <string>

template<typename T>
class TVector{
private:
    size_t size;
    size_t capacity;
    T* data;
    const unsigned DEFAULT_CAP = 7;
public:
    TVector(): size(0), capacity(DEFAULT_CAP), data(new T[DEFAULT_CAP]) {}
    ~TVector(){if (data) delete [] data;}
    TVector(size_t size);
    TVector(TVector<T> const & object);
    TVector(size_t size, const T &value);
    void Print() const;
    T& operator [](size_t idx) const {return data[idx];}
    T& operator [](size_t idx) {return data[idx];}
    size_t Size() const {return size;}
    void PushBack(T const & value);
};

template<typename T>
TVector<T>::TVector(size_t size) : size(size), capacity(size), data(new T[size]) { }

template<typename T>
TVector<T>::TVector(const TVector<T> &object)  {
    size = object.size;
    capacity = object.capacity;
    data = new T[capacity];
    for(int i = 0; i < size; ++i){
        data[i] = object.data[i];
    }
}


template<typename T>
TVector<T>::TVector(size_t size, const T &value): size(size), capacity(size), data(new T[size]) {
    for (int i = 0; i < size; ++i) {
        data[i] = value;
    }
}

template<typename T>
void TVector<T>::PushBack(const T &value) {
    if (size == capacity) {
        capacity = capacity * 2 + 1;
        T* upd_data = new T[capacity];
        for (int i = 0; i < size; ++i) {
            upd_data[i] = data[i];
        }
        if (data) {
            delete data;
        }
        data = upd_data;
    }
    data[size] = value;
    ++size;
}

template<typename T>
void TVector<T>::Print() const {
    for (int i = 0; i < size; ++i){
        std::cout << data[i] << "\n";
    }
}