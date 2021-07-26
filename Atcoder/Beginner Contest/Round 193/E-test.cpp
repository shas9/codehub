#include <bits/stdc++.h>
#include <atcoder/math>
using namespace std;
using ll = int64_t;
const ll INF = numeric_limits<ll>::max() / 4;
void solve(){
    ll X, Y, P, Q;
    cin >> X >> Y >> P >> Q;
    ll ans = INF;
    for(ll t1 = X; t1 < X + Y; t1++) for(ll t2 = P; t2 < P + Q; t2++){
        auto [t, lcm] = atcoder::crt({t1, t2}, {(X + Y) * 2, P + Q});
        if(lcm == 0) continue;
        if(ans > t) ans = t;
    }
    if(ans == INF) puts("infinity");
    else cout << ans << endl;
}
int main(){
    ll T;
    cin >> T;
    while(T--) solve();
}
