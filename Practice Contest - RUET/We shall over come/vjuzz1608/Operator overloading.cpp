#include <iostream>

using namespace std;

class A
{
    int x, y;

public:

    void input(int a, int b)
    {
        x = a;
        y = b;
    }

    void display()
    {
        cout << x << " " << y << endl;
    }

    A operator + (A a1)
    {
        A temp;

        temp.x = x + a1.x;
        temp.y = y + a1.y;

        return temp;
    }

    A operator++()
    {
        x++;
        y++;
    }

    A operator -(A a1)
    {
        x = a1.x;
        y = a1.y;
    }
};


int main()
{
    A a1;
    A a2;

    a1.input(10,20);
    a2.input(20,30);

    A a3;

    a3 - a1;

    a3.display();
}
