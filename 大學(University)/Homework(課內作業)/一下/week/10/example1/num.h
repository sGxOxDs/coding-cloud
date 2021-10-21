// demo hide implementation in C++
#ifndef NUM_H
#define NUM_H

class num
{
    public:
        num();
        ~num();
        void set (int param);
        int get (void) const;
        void addTwo (void);
    private:
        class implementation;
        implementation * impl;
};

#endif // NUM_H
