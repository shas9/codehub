#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    int w,h;
public:
    void input()
    {
        cin>>w>>h;
    }
};

class calArea: public A
{   public:
    void area()
    {
        cout << w << " - " << h << endl;
        cout<<w*h;
    }
};

int main()
{

    calArea obj2;

    obj2.input();
    obj2.area();
};
