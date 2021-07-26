#include <bits/stdc++.h>

using namespace std;


/*
int = (-2*10^9 to +2*10^9)
long long int = (-2*10^63 to +2*10^63)


200000
1000000000 1 1 1 1 1 1 1 1

200000 * 1000000000 = 2 * 10^14
*/
int main()
{
    int n;

    cin >> n;

    long long int ans = 0;
    int mx = -1e10;

    for(int i = 1; i <= n; i++)
    {
        int in;

        cin >> in;

        if(mx < in) mx = in;

        ans += (mx - in);
    }

    cout << ans << "\n";
}

