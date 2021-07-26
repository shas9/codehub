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

#define printcase(indexing,ans) printf("Case #%lld: %lld\n", indexing, ans)
#define printimp(indexing) printf("Case #%lld: IMPOSSIBLE\n", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

char mp[100];
ll d;

ll arr_s[100];
ll arr_mp[100];
ll arr_2[50];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    arr_2[0] = 1;

    for(i = 1; i <= 40; i++)
    {
        arr_2[i] = 2 * arr_2[i- 1];
    }

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(d);

        ss(mp);

        ll tot_s = 0;

        ll sz = strlen(mp);
        memset(arr_s, -1, sizeof arr_s);
        memset(arr_mp, -1, sizeof arr_mp);

        for(i = 0; i < sz; i++)
        {
            if(mp[i] == 'C') arr_mp[i] = 0;
            else arr_mp[i] = 1, tot_s++;
        }

        if(tot_s > d)
        {
            printimp(cs);
            continue;
        }

        ll temp = 0;

        for(i = 0; i < sz; i++)
        {
            if(arr_mp[i] == 0) temp++;
            else arr_s[i] = temp;
        }

        ll sum = 0;

        for(i = 0; i <= 35; i++)
        {
            if(arr_s[i] >= 0) sum += arr_2[arr_s[i]];
        }

//        cout << sum << endl;

        ll cnt = 0;

        while(sum > d)
        {
            cnt++;

            for(i = sz - 1; i > 0; i--)
            {
                if(arr_mp[i] == 1 && arr_mp[i - 1] == 0)
                {
                    swap(arr_mp[i],arr_mp[i-1]);

                    sum -= arr_2[arr_s[i] - 1];

                    arr_s[i - 1] = arr_s[i] - 1;
                    arr_s[i] = 0;
                    break;
                }
            }

//            cout << sum << endl;
        }

        printcase(cs,cnt);
    }


}


