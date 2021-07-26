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

string name[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December", "NO"};
ll cnt[3003];

ll conv(string months, ll date, ll year)
{
    ll ret = 0;

    if(year == 1944) ret += 480 * 2;
    if(year == 1943) ret += 480;

//    cout << ret << " ";
//
    for(ll i = 0; i <= 12; i++)
    {
        assert(i < 12);

        if(months == name[i])
        {
            ret += (i * 40);
            break;
        }
    }

//    cout << ret << " ";

    ret += date;

//    cout << ret << "\n";

    assert(212 <= ret && ret <= (480 * 3));

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> n;

    for(ll i = 1; i <= n; i++)
    {
        string monts, x;
        ll date, year;

        cin >> monts >> date >> x >> year;

        ll ddate = conv(monts, date, year);

        cnt[ddate]++;
    }

    for(ll i = 1; i <= 3000; i++) cnt[i] += cnt[i - 1];

    cin >> n;

    for(ll i = 1; i <= n; i++)
    {
        string monts, x;
        ll date, year;

        cin >> monts >> date >> x >> year;

        l = conv(monts, date, year);

        cin >> monts >> date >> x >> year;

        r = conv(monts, date, year);

        assert(l <= r);

        cout << cnt[r] - cnt[l - 1] << "\n";
    }
}
