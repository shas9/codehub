#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ans = 0;

    int n, a, b;

    cin >> n >> a >> b;

    for(int i = 1; i <= n; i++) //n = 100
    {
        int behind = (n - i);
        int front = (i - 1);

        if(a <= front && b >= behind) ans++;
    }

    cout << ans << "\n";
}

