#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <class T>
class DynamicArray {
private:
    T* arr;
    int size;

public:
    DynamicArray(int s = 10) {
        size = s;
        arr = new T[size];
    }

    T& operator[](int index) {
        return arr[index];
    }

    T* getArray() {
        return arr;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

#endif