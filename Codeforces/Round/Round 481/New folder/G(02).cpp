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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 200


using namespace std;

ll quest[maxn], exam[maxn], tme[maxn];
ll day[maxn];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n >> m)
    {
        memset(quest,0,sizeof quest);
        memset(exam,0,sizeof exam);
        memset(tme,0,sizeof tme);
        memset(day,0,sizeof day);

        for(i = 1; i <= m; i++)
        {
            cin >> quest[i] >> exam[i] >> tme[i];
        }

        for(i = 1; i <= n; i++)
        {
            bool ase = 0;
            for(j = 1; j <= m; j++)
            {
                if(exam[j] == i)
                {
                    if(tme[j] != 0)
                    {
//                        cout << i << " " << tme[j] << endl;
                        cout << -1 << endl;
                        exit(0);
                    }

                    day[i] = m + 1;

                    ase = 1;
                    break;
                }
            }

            if(ase) continue;

            ll kakedibo = 0;
            ll mx = mxlld;

            for(j = 1; j <= m; j++)
            {
                if(quest[j] > i) continue;

                if(tme[j] == 0 || exam[j] < i) continue;

                if(mx > exam[j])
                {
                    mx = exam[j];
                    kakedibo = j;
                }

            }

            //cout << i << " " << j << endl;

            day[i] = kakedibo;
            tme[kakedibo]--;
        }


        for(i = 1; i <= n; i++)
            cout << day[i] << " ";


    }


}

