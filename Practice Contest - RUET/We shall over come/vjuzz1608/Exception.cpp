#include <iostream>

using namespace std;

class A
{
    int a, b;
public:

    A(int x, int y)
    {
        a = x;
        b = y;
    }
    void division()
    {
        try
        {
            if(b == 0)
            {
                throw 42;
            }

            cout << a/b;

        }

        catch(int x)
        {
            cout << "Error: " << x << endl;
        }
    }
};

int main()
{
    A a1(20,0);
    a1.division();
}


