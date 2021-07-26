 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

map < ll, ll > mp;

bool is10(ll x)
{
    ll sum = 0;

    while(x)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum == 10;
}

void gen()
{
    ll cnt = 0;
    ll num = 19;

    while(cnt <= 10000)
    {
        if(is10(num))
        {
            mp[++cnt] = num;
        }

        num++;
    }

    return;
}
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    gen();

    while(cin >> n)
    {
        cout << mp[n] << '\n';
    }


}


