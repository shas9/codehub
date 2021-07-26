#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d1, d2, d3;

    cin >> d1 >> d2 >> d3;

    if(d1 >= (d2 + d3))
    {
        cout << (d2 + d3) * 2 << "\n";
    }
    else if(d2 >= (d1 + d3))
    {
        cout << (d1 + d3) * 2 << "\n";
    }
    else if(d3 >= (d1 + d2))
    {
        cout << (d1 + d2) * 2 << "\n";
    }
    else
    {
        cout << (d1 + d2 + d3)  << "\n";
    }
}

