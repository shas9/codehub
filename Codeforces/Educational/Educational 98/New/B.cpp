// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

vector < ll > vec;

void test()
{
    ll n;
    cin >> n;
    vec.resize(n);
    ll tot = 0;

    for(auto &it: vec)
    {
        cin >> it;
        tot += it;
    }

    sort(vec.rbegin(),vec.rend());

    vec.push_back(0);

    ll mx = 0;
    ll ans = 0;

    for(ll i = 0; i < n; i++)
    {
        ll tmx = max(mx, vec[i + 1]);
        ll ttot = tot - vec[i];

        ll need = (n - 1) * tmx;

        cout << i << ": " << tmx << " " << need << " " << tot << "\n";

        if(need > tot)
        {
            ans += need - tot;
            vec[i] += need - tot;
        }
        else
        {
            ll m = (n - 1);
            ll add = (m - (tot % m)) % m;

            ans += add;
            vec[i] += add;
        }

        cout << ans << "\n";

        tot = ttot + vec[i];

        mx = max(mx, vec[i]);
    }

    cout << ans << "\n";
}

void test2()
{
    ll n;
    cin >> n;
    vec.resize(n);
    ll tot = 0;

    for(auto &it: vec)
    {
        cin >> it;
        tot += it;
    }

    sort(vec.begin(),vec.end());


    ll mx = 0;
    ll ans = 0;

    for(ll i = 0; i < n; i++)
    {
        ll tmx = max(mx, vec.back());
        ll ttot = tot - vec[i];

        ll need = (n - 1) * tmx;

//        cout << i << ": " << tmx << " " << need << " " << tot << "\n";

        if(need > tot)
        {
            ans += need - tot;
            vec[i] += need - tot;
        }
        else
        {
            ll m = (n - 1);
            ll add = (m - (tot % m)) % m;

            ans += add;
            vec[i] += add;
        }

//        cout << ans << "\n";

        tot = ttot + vec[i];

        mx = max(mx, vec[i]);
    }

    cout << ans << "\n";
}

void test3()
{
	ll n;
	cin >> n;
	vec.resize(n);
	ll mx = 0;
	ll tot = 0;

	for(auto &it: vec)
	{
		cin >> it;
		mx = max(mx, it);
		tot += it;
	}

	ll need = (mx * (n - 1));

	ll ans;

	if(need > tot) ans = need - tot;
	else ans = ((n - 1) - (tot % (n - 1))) % (n - 1);

	cout << ans << "\n";

	return;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		test3();
    }


}



