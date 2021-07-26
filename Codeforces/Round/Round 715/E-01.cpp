 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

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

vector < ll > vec;

bool solve(ll n, ll k, ll pos)
{
    if(k > (1LL << (n - 1))) return 0;

    ll cnt = 1;
    ll sum = 0;

    for(ll i = n - 2; i >= 0; i--)
    {
        if(sum + (1LL << i) >= k)
        {
            for(ll j = cnt; j >= 1; j--)
            {
                vec.push_back(j + pos);
            }

            return solve(n - cnt, k - sum, pos + cnt);
        }

        sum += (1LL << i);
        cnt++;
    }

    for(ll j = cnt; j >= 1; j--)
    {
        vec.push_back(j + pos);
    }

    return 1;
}


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> k;
        vec.clear();

        ll cnt = 0;

        while(n > 62)
        {
            cnt++;
            vec.push_back(cnt);
            n--;
        }

        if(solve(n,k,cnt))
        {
            for(auto it: vec) cout << it << " ";

            cout << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }


}

