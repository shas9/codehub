#include <iostream>

using namespace std;

class Base
{
    int a, b;
public:

    virtual void fun()
    {
        cout << "Base class called." << endl;
    }

};

class derived: public Base
{
    int a, b;
public:
    void fun()
    {
        cout << "Derived class called" << endl;
    }
};

void myfun(Base *obj)
{
    obj -> fun();
}

int main()
{
    myfun(new Base);
    myfun(new derived);
}
