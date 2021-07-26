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

struct node
{
    ll first, second, id;
};

node arr[1005];
ll cumh[1005];

bool comp(node a, node b)
{
    if(a.first == b.first) return a.second > b.second;

    return a.first > b.first;
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
        slld(n);

        ll tot = 0;
        ll exp = 0;

        for(i = 1;  i <= n; i++)
        {
            slld(arr[i].first);
            slld(arr[i].second);

            tot += arr[i].second;

            exp += (arr[i].first * arr[i].second);

            arr[i].id = i;
        }

        sort(arr + 1, arr + 1 + n, comp);

        ll mxu = exp, mxd = tot;

        double ans = mxu / mxd;

        for(i = 1; i <= n; i++)
        {
            cumh[i] = cumh[i - 1] + arr[i].first;

            double zz = (1.0 * (exp + cumh[i])) / (tot + i);

//            cout << zz << " ";

            if(zz > ans)
            {
                ans = zz;
                mxu = exp + cumh[i];
                mxd = (tot + i);
            }
        }

////        cout << endl;
//
//        cout << ans << endl;

        for(i = 1; i <= n; i++)
        {
            double zz = (1.0 * (exp + cumh[i])) / (tot + i);

            if(zz == ans)
            {
//                cout << exp << " " << cumh[i] << endl;
                mxu = exp + cumh[i];
                mxd = (tot + i);

//                                 cout << " -- " << ans << " " << mxu << " " << mxd << " " << __gcd(mxu,mxd) << endl;
                ll gc = __gcd(mxu,mxd);

                mxu /= gc;
                mxd /= gc;


                cout << mxu << "/" << mxd << endl;

                cout << i << endl;

                for(j = 1; j <= i; j++)
                {
                    cout << arr[j].id << " ";
                }

                cout << endl;
                break;


            }
        }
    }


}


