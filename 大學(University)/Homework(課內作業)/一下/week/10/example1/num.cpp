#include "num.h"

// implementation class
class num::implementation
{
    public:
        int n;
    public:
        void addOne (void);
};

void num::implementation::addOne (void)
{
    ++n;
}

// normal class
num::num()
{
    impl = new implementation;
}

num::~num()
{
    delete impl;
}

void num::set (int param)
{
    impl->n = param;
}

int num::get (void) const
{
    return (impl->n);
}

void num::addTwo (void)
{
    impl->addOne();
    impl->addOne();
}

