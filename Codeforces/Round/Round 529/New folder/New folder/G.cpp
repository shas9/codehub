#include <bits/stdc++.h>`

using namespace std;

int main()
{

    long long a, b, c, i;

    cin >> a >> b;

    if(abs(b - a) >= 5) cout << 0 << endl;
    else
    {
        c = 1;

        for(i = a + 1; i <= b; i++)
        {
            c = (c * (i % 10)) % 10;
        }

        cout << c << endl;

    }


}



