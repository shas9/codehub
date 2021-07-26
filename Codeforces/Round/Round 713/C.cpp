// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n")
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

string in, out;
ll a, b;

void solve()
{
//    cout << in << "\n";

//    cout << a << " " << b << " " << in << "\n";

    for(auto it: in)
    {
        if(it == '0') a--;
        else if(it == '1') b--;
    }

//    cout << a << " " << b << " " << in << "\n";

    ll n = in.size();

    for(ll i = 0; i < n; i++)
    {
        if(in[i] == '?' && in[n - i - 1] == '?') continue;

        if(in[i] == '?')
        {
            if(in[n - i - 1] == '0')
            {
                a--;
                in[i] = '0';
            }
            else
            {
                b--;
                in[i] = '1';
            }
        }
    }


//    cout << a << " " << b << " " << in << "\n";

    for(ll i = 0; i < n; i++)
    {
        if(in[i] == '?' && in[n - i - 1] == '?')
        {
            if(i == (n - i - 1))
            {
                if(a & 1) in[i] = '0', a--;
                else in[i] = '1', b--;
            }
            else
            {
                if(a > b)
                {
                    in[i] = in[n - i - 1] = '0';
                    a -= 2;
                }
                else
                {
                    in[i] = in[n - i - 1] = '1';
                    b -= 2;
                }
            }
        }
    }

//    cout << a << " " << b << " " << in << "\n";

    for(ll i = 0; i < n; i++)
    {
        if(in[i] != in[n - i - 1]) in = "-1";
    }
    if(a || b)
    {
        in = "-1";
    }

    return;

}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> a >> b;
        cin >> in;

        solve();

        cout << in << "\n";
    }


}

