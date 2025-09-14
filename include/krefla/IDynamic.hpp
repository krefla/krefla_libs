#pragma once

#include "BaseInterator.hpp"

template<class T>
class IDynamic{
    public:
        virtual BaseInterator& start() const = 0;
        virtual BaseInterator& end() const = 0;
        virtual bool is_empty() const = 0;
        virtual unsigned int size() const = 0;
        virtual ~IDynamic() = default;
};