#include <bits/stdc++.h>
using namespace std;

#define ll  long long

int main() {
    ll n, x, i;

    cin >> n >> x;

    ll a[n], sum = 0, maximum = 0;

    for(i = 0; i < n; i++) {
        cin >> a[i];

        sum += a[i];
    }

    sum = abs(sum);
    ll ans;

    if(sum <= x) {
        ans = 1;
    }
    else {
        ans = sum / x + 1;
    }

    cout << ans << endl;

    return 0;
}
