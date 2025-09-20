#pragma once

template<class T>
struct BaseInterator
{   
    T data;
    BaseInterator<T>* next;

    public:
        virtual BaseInterator<T>* get_next() = 0;
};
