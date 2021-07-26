#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, t;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &a);

        if((360 % (180 - a)) == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
