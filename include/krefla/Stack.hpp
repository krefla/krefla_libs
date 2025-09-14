#pragma once
#include "IDynamic.hpp"

template<class T>
struct stack_node;

template<class T>
using stack_interator = stack_node<T>*;

template<class T>
struct stack_node
{
    T data;
    stack_interator<T> next;

    stack_node(T value) : data(value){
        next = nullptr;
    };
    stack_node& operator++(){
        data = next->data;
        next = next->next;
        return *this;
    }
};

template <class T>
class Stack : public IDynamic<T>
{
    private:
        stack_interator<T> top;
    public:
        Stack(){
            top = nullptr;
        }
        Stack(const stack_point<T> it){
            top = it;
        }
        Stack(const T& value){
            stack_interator<T> it = new stack_node(value);
            top = it;
        }

        void add(const T& value) override {
            stack_interator<T> it = new stack_node(value);
            it->next = top;
            top = it;
        }

        T pop() override{
            stack_interator<T> tmp = top;
            top = top->next;
            T data(tmp->data);
            return data;
        }

        T get() const {
            return top->data;
        }

        bool is_empty() const {
            return (top == nullptr);
        }

        unsigned int size() const {
            unsigned int size = 0;
            stack_interator<T> tmp = top;
            while(tmp != nullptr){
                size++;
            }
            return size;
        }

        ~Stack(){
            while(top != nullptr){
                stack_interator<T> tmp = top;
                top = top->next;
                delete tmp;
            }
        }
};
