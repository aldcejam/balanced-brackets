#include "stack.h"
#include <iostream>

template <typename T>
Stack<T>::Stack(int size)
{
    capacity = size;
    stackArray = new T[capacity];
    top = -1;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] stackArray;
}

template <typename T>
bool Stack<T>::isFull() {
    return top == capacity - 1;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return top == -1;
}

template <typename T>
void Stack<T>::push(T item)
{
    if (isFull())
    {
        std::cout << "Stack is full. Cannot push" << std::endl;
        return;
    }
    stackArray[++top] = item;
}

template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty. Cannot pop" << std::endl;
        return T();
    }
    return stackArray[top--];
}

template <typename T>
T Stack<T>::peek()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty. Nothing to peek." << std::endl;
        return T();
    }
    return stackArray[top];
}

template<typename T>
int Stack<T>::size() {
    return top + 1;
}

template class Stack<char>;
