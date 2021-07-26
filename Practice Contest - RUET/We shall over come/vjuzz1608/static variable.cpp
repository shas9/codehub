#include <iostream>

using namespace std;

class A
{
    static int countvalue;
    int x;

public:

    A()
    {
        countvalue++;
    }
    void getvalue(int a)
    {
        x = a;
        cout << countvalue << endl;
    }
};

int A::countvalue = 0;

int main()
{
    A a1;
    a1.getvalue(10);
    A b1;
    b1.getvalue(20);
}

