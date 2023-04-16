// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
private:
    T* array;
    int lst, fst, num;

public:
    TPQueue() : lst(0), first(0), num(0) {
        array = new T[size];
    }
    bool isEmpty() const {
        return 0 == num;
    }
    bool isFull() const {
        return num == size;
    }
    void Push(const T& value) {
        if (isFull()) {
            throw std::string("full!");
        }
        else {
            int n = lst;
            array[lst % size] = value;
            T temp = array[n % size];
            while (array[(n - 1) % size].prior < array[n % size].prior && fst < n) {
                temp = array[n % size];
                array[n % size] = array[(n - 1) % size];
                array[(n - 1) % size] = temp;
                n--;
            }
            num++;
            lst++;
        }
    }
    const T& Pop() {
        if (isEmpty()) {
            throw std::string("empty!");
        }
        else {
            num--;
            return array[fst++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
