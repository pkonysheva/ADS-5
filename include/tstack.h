// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
  private:
    T data[size];
    int Index;

public:
    TStack() : Index(0) {}

    bool isEmpty() const {
        return Index == 0;
    }

    bool isFull() const {
        return Index >= size;
    }

    void push(const T& value) {
        if (!isFull()) {
            data[Index++] = value;
        }
    }

    T pop() {
        if (!isEmpty()) {
            return data[--Index];
        }
        throw std::runtime_error("Stack is empty");
    }

    const T& top() const {
        if (!isEmpty()) {
            return data[Index - 1];
        }
        throw std::runtime_error("Stack is empty");
    }
};

#endif  // INCLUDE_TSTACK_H_
