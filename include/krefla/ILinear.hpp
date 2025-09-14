#include "IDynamic.hpp"

template <class T>
class ILinear : public IDynamic<T>
{
    public:
        virtual void push(const T&)= 0;
        virtual T pop() = 0;
        virtual T get() const = 0;
        virtual ~ILinear() = default;
};
