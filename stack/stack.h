#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack {
    private:
        int top;
        int capacity;
        T* stackArray;
    public:
        Stack(int size);
        ~Stack();

        bool isFull();
        bool isEmpty();

        void push(T item);
        T pop();
        T peek();
        int size();
};

#endif
