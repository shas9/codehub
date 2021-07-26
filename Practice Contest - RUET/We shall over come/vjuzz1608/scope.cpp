#include <iostream>

//using namespace std;

int x = 20;

namespace outer
{
    int m = 100;
    int a = 400, b, c;
}

namespace outer2
{
    int m = 200;
    namespace inner
    {
        int m = 300;
    }
}

using namespace std;

int main()
{
    using namespace outer;

    int a = 500;
    cout << m << endl;
    cout << outer :: a << endl;
    cout << outer2 :: m << endl;
    cout << outer2 :: inner :: m << endl;
}
