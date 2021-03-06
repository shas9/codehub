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

vector < ll > vec;

bool possible(ll mid, ll coin)
{
    for(ll i = 0; i < vec.size(); i++)
    {
        if(vec[i] <= mid) continue;

        ll vag = (vec[i] - 1) / mid;

        if(coin < vag) return 0;

        coin -= vag;
    }

    return 1;
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
        slld(n);
        slld(m);

        vec.clear();

        ll last = 0;

        for(i = 1; i <= n; i++)
        {
            slld(input);

            if(i > 1)
            {
                vec.push_back(input - last);
            }

            last = input;
        }

        sort(vec.begin(), vec.end());

        ll lo = 1;
        ll hi = vec[vec.size() - 1];
        ans = hi;

//        for(i = 0; i < vec.size(); i++) cout << vec[i] << " ";
//        cout << endl;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

//            cout << mid << endl;

            if(possible(mid, m))
            {
                hi = mid - 1;
                ans = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        printf("Case #%lld: %lld\n", cs, ans);
    }


}



