// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

string str;
string ans;

bool solve(ll n, ll m)
{
    if(n % m) return 0;

    set < ll > st;
    ll freq[30];
    memset(freq,0,sizeof freq);

    ll pos = -1;

    for(ll i = 0; i < n; i++)
    {
        ll mx = str[i] - 'a';

        if(mx == 25) continue;

        ll need = 0;

        for(ll j = 0; j < 26; j++)
        {
            need += (freq[j] % m);
        }

        auto it = st.upper_bound(mx);

        if(it == st.end()) need += m;

        if((n - need) % m == 0) pos = i;

        freq[str[i] - 'a']++;
        st.insert(str[i] - 'a');
    }

    bool on = 1;

    for(ll i = 0; i < 26; i++)
    {
        if(freq[i] % m) on = 0;
    }

    if(on)
    {
        ans = str;
        return on;
    }

    if(pos == -1) return 0;

    ans = "";
    st.clear();
    memset(freq,0,sizeof freq);

    for(ll i = 0; i < pos; i++)
    {
        ans += str[i];
        freq[str[i] - 'a']++;
        st.insert(str[i] - 'a');
    }

    ll mx = str[i] - 'a';

    if(mx == 25) continue;

    ll need = 0;

    for(ll j = 0; j < 26; j++)
    {
        need += (freq[j] % m);
    }

    auto it = st.upper_bound(mx);

    ans[]

}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> m >> str;

        if(solve(n,m)) cout << ans << "\n";
        else cout << -1 << "\n";
    }


}



