// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <stdexcept>

template<typename T, size_t kArraySize>
class TStack {
 private:
  T data[kArraySize];
  size_t topIndex;

 public:
  TStack() : topIndex(0) {}

  bool isEmpty() const {
    return topIndex == 0;
  }

  bool isFull() const {
    return topIndex >= kArraySize;
  }

  void push(const T& value) {
    if (!isFull()) {
      data[topIndex++] = value;
    }
  }

  T pop() {
    if (isEmpty()) {
      throw std::runtime_error("Stack is empty");
    }
    return data[--topIndex];
  }

  const T& top() const {
    if (isEmpty()) {
      throw std::runtime_error("Stack is empty");
    }
    return data[topIndex - 1];
  }
};

#endif  // INCLUDE_TSTACK_H_
