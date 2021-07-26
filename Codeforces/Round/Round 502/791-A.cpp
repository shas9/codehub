#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, ans;
    cin >> n >> m;
    ans = 0;
    while(n <= m) n *= 3, m *= 2, ans++;
    cout << ans << endl;
}


