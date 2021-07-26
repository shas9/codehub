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
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < pll > vec;

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
        slld(n);
        slld(m);

        vec.clear();
        ll sum = 0;

        for(i = 1; i <= n; i++)
        {
            slld(input);

            vec.push_back(make_pair(input,i));

            sum += (input * 2);
        }

        if(n > m || n == 2)
        {
            cout << -1 << endl;
            continue;
        }

        sort(vec.begin(),vec.end());

        ll diff = m - n;

        sum += (diff * (vec[0].first + vec[1].first));

        cout << sum << endl;

        for(i = 1; i <= n; i++)
        {
            if(i == n)
            {
                cout << i << " " << 1 << endl;
                continue;
            }

            cout << i << " " << i + 1 << endl;
        }

        while(diff--)
        {
            cout << vec[0].second << " " << vec[1].second << endl;
        }
    }

    return 0;


}


