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

ll arr[5];

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
        for(i = 1; i <= 3; i++)
        {
            slld(arr[i]);
        }

        sort(arr + 1, arr + 4);

        ans = mxlld;
        for(i = 1; i <= 3; i++)
        {
            ll a = arr[1], b = arr[2], c = arr[3];
            if(i == 2)
            {
                arr[1]++;
            }
            else if(i == 3)
            {
                arr[1]--;
            }

            for(ll ii = 1; ii <= 3; ii++)
            {
                if(ii == 2)
                {
                    arr[2]++;
                }
                else if(ii == 3)
                {
                    arr[2] -= 2;
                }
                for(ll iii = 1; iii <= 3; iii++)
                {
                    if(iii == 2)
                    {
                        arr[3]++;
                    }
                    else if(iii == 3)
                    {
                        arr[3] -= 2;
                    }

                    ll sum = 0;

//                    cout << arr[1] << " " << arr[2] << " " << arr[3] << endl;
                    for(j = 1; j <= 3; j++)
                    {
                        for(k = j + 1; k <= 3; k++)
                        {
                            sum += abs(arr[j] - arr[k]);
                        }
                    }
                    ans = min(sum,ans);
                }

                arr[3] = c;
            }

            arr[2] = b;
        }

        cout << ans << endl;
    }


}

