#pragma once

template<class T>
struct BaseInterator
{   
    protected:
        T data;
        IInterator* next;
    public:
        virtual void go_next() = 0;
        virtual IInterator* get_next() const = 0;
        virtual void set_next(IInterator*) = 0;
        virtual T value() const = 0; 
        virtual void set_value(T) = 0; 
};
