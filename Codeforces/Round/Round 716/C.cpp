 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x
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

void gen()
{
    ll n = 20;
    for(ll i = 2; i <= n; i++)
    {
        vector < ll > ans;

        for(ll k = 1; k < (1 << (i - 1)); k++)
        {
            ll product = 1;
            ll cnt = 0;

            for(ll j = 0; j <= 25; j++)
            {
                if(check(k,j))
                {
                    product *= (j + 1);
                    cnt++;
                }
            }

            if(product % i == 1)
            {
                if(ans.size() < cnt)
                {
                    ans.clear();

                    for(ll j = 0; j <= 25; j++)
                    {
                        if(check(k,j))
                        {
                            ans.push_back(j + 1);
                        }
                    }
                }
            }
        }

        cout << i << " : ";
        for(auto it: ans) cout << it << " ";
        cout << "\n";
    }
}
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    gen();

    while(cin >> n)
    {
        vector < ll > ans;
        ll lim = (n - 2);

        if(n <= 4)
        {
            cout << "1\n1\n";
        }
        else
        {
            ll gun = 1;

            for(ll i = 1; i <= lim; i++)
            {
                if(__gcd(i,n) == 1)
                {
                    ans.push_back(i);
                    gun = (gun * i) % n;
                }
            }

            if((gun * (n - 1)) % n == 1) ans.push_back(n - 1);
            else assert(gun == 1);

            cout << ans.size() << "\n";

            for(auto it: ans)
            {
                cout << it << " ";
            }

            cout << "\n";
        }
    }


}



