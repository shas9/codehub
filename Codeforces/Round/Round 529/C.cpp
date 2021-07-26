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

map < ll, ll > p2;

multiset < ll, greater < ll > > arr;
ll p22[50];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    p2.clear();

    flag = 1;

    p2[flag] = 1;
    p22[0] = 1;
    for(i = 1; i <= 40; i++)
    {
        flag *= 2;

        p2[flag] = 1;
        p22[i] = flag;
    }


    while(cin >> n >> k)
    {
        arr.clear();

        for(i = 0; i <= 34; i++)
        {
            if(check(n,i))
            {
                arr.insert(p22[i]);
            }
        }

        ll cnt = 0;

       multiset < ll, greater < ll > > :: iterator itr;

        while(1)
        {
            if(arr.size() > k)
            {
                cout << "NO" << endl;
                break;
            }

            if(arr.size() == k)
            {
                cout << "YES" << endl;


                for(itr = arr.begin(); itr != arr.end(); itr++)
                {
                    cout << *itr << " ";
                }

                cout << endl;
                break;
            }

            bool on = 0;
            for(itr = arr.begin(); itr != arr.end(); itr++)
            {
                ll x = *itr;
                ll z = *itr;

                if(x % 2) continue;

                x /= 2;

                if(p2[x] == 0) continue;

                on = 1;


                arr.insert(x);
                arr.insert(x);

                itr = arr.find(z);
                arr.erase(itr);
//                for(itr = arr.begin(); itr != arr.end(); itr++)
//                {
//                    cout << *itr << " ";
//                }
//
//                cout << endl;


                break;
            }

            if(on == 0)
            {
                cout << "NO" << endl;
                break;
            }

        }


    }


}



