#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll d;

    while(cin >> n >> d >> k)
    {
        ll maxd = 1;
        ll now = 1 + k;
        ll last = k;

        while(now + (last * (k - 1)) < n)
        {
            now += last * (k - 1);
            last *= (k - 1);
            maxd++;
        }

        maxd *= 2;

        ll need = n - now;

        if(need <= (k - 1)) maxd++;
        else maxd += 2;

        if(maxd > d)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        queue < ll > q;

        for(i = 2; i <= k + 1; i++) q.push(i), cout << 1 << " " << i << endl;

        ll curr = k + 2;

        while(!q.empty())
        {
            ll top = q.front();
            q.pop();
            for(i = 1; i < k; i++)
            {
                q.push(curr);

                cout << top << " " << curr << endl;

                if(curr == n) break;

                curr++;
            }

            if(curr == n) break;
        }




    }

}


