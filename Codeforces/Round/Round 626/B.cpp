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

ll arr[40004];
ll brr[40004];
vector < ll > divv;

ll ona[40004];
ll onb[40004];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
        memset(ona,0,sizeof ona);
        memset(onb,0,sizeof onb);
        divv.clear();

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        for(i = 1; i <= m; i++)
        {
            slld(brr[i]);
        }


        arr[n + 1] = 1;

        for(i = n; i >= 1; i--)
        {
            if(arr[i] == 1)
            {
                if(arr[i + 1] == 0)
                {
                    ona[i] = i;
                }
                else ona[i] = max(i,ona[i + 1]);
            }
            else
            {
                if(arr[i + 1] == 1)
                {
                    ona[i] = i + 1;
                }
                else
                {
                    ona[i] = ona[i + 1];
                }
            }
        }

        brr[m + 1] = 1;

        for(i = m; i >= 1; i--)
        {
            if(brr[i] == 1)
            {
                if(brr[i + 1] == 0)
                {
                    onb[i] = i;
                }
                else onb[i] = max(i, onb[i + 1]);
            }
            else
            {
                if(brr[i + 1] == 1)
                {
                    onb[i] = i + 1;
                }
                else
                {
                    onb[i] = onb[i + 1];
                }
            }
        }

        for(i = 1; i * i <= k; i++)
        {
            if(k % i) continue;

            divv.push_back(i);
        }

        i = 1;

        ans = 0;

        while(i <= n)
        {
            if(arr[i] == 0)
            {
                i = ona[i];
            }

            if(i > n) break;

//            cout << "~~" << i << endl;

            ll lft = ona[i] - i + 1;

            j = 1;

            while(j <= m)
            {
                if(brr[j] == 0)
                {
                    j = onb[j];
                }

                if(j > m) break;

//                cout << "~" << j << endl;

                ll rgt = onb[j] - j + 1;

//                cout << lft << " " << rgt << endl;

                for(ll p = 0; p < divv.size(); p++)
                {
                    ll x = divv[p];
                    ll y = k / x;

                    if(lft >= x && rgt >= y)
                    {
                        ans += (lft - x + 1) * (rgt - y + 1);
                    }

                    if(rgt >= x && lft >= y && x != y)
                    {
                        ans += (rgt - x + 1) * (lft - y + 1);
                    }

//                    cout << ans << endl;
//                    cout << p << endl;
                }

                j = onb[j];
                j++;
            }

            i = ona[i];
            i++;


        }

        cout << ans << endl;
    }


}



