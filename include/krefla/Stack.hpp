#pragma once
#include "ILinear.hpp"

template<class T>
struct stack_node : public BaseInterator<T>
{
    stack_node(const T& value) {
        this->data = value;
        this->next = nullptr;
    };

    stack_node<T>* get_next() override {
        return (stack_node<T>*)this->next;
    }

};

template<class T>
using stack_interator = stack_node<T>*;


template <class T>
class Stack : public ILinear<T>
{
    private:
        stack_interator<T> top;
    public:
        Stack(){
            top = nullptr;
        }
        Stack(const stack_interator<T> it){
            top = it;
        }
        Stack(const T& value){
            stack_interator<T> it = new stack_node<T>(value);
            top = it;
        }

        stack_interator<T> start() const override {
            return top;
        }
        stack_interator<T> end() const override {
            return nullptr;
        }

        void push(const T& value) override {
            stack_interator<T> it = new stack_node<T>(value);
            it->next = top;
            top = it;
        }

        T pop() override {
            stack_interator<T> tmp = top;
            top = top->get_next();
            T data(tmp->data);
            delete tmp;
            return data;
        }

        T get() const override {
            return top->data;
        }

        bool is_empty() const override {
            return (top == nullptr);
        }

        unsigned int size() const override {
            unsigned int size = 0;
            stack_interator<T> tmp = top;
            while(tmp != nullptr){
                size++;
                tmp = tmp->get_next();
            }
            return size;
        }

        ~Stack(){
            while(top != nullptr){
                stack_interator<T> tmp = top;
                top = top->get_next();
                delete tmp;
            }
        }
};
