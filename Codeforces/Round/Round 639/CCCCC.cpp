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

vector < ll > vec[200005];
ll arr[200005][5];
ll freq[200005];
ll ans[200005];
bool vis[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    slld(n);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= 3; j++)
        {
            slld(input);

            vec[input].push_back(i);

            arr[i][j] = input;

            freq[input]++;
        }
    }

    for(i = 1; i <= n; i++)
    {
        if(freq[i] == 1)
        {
            ans[1] = i;
            break;
        }
    }

    for(i = 0; i < 1; i++)
    {
        ll top = vec[ans[1]][i];

        for(j = 1; j <= 3; j++)
        {
            ll x = arr[top][j];

            ans[freq[x]] = x;
        }
    }

    vis[ans[1]] = 1;
    vis[ans[2]] = 1;
    vis[ans[3]] = 1;
    for(i = 3; i < n; i++)
    {
        ll x = ans[i];
        bool flag = 1;

//        cout << i << endl;

        for(j = 0; j < vec[x].size() && flag; j++)
        {

            ll top = vec[x][j];

            for(ll ii = 0; ii < 3 && flag; ii++)
            {
                for(ll jj = 0; jj < 3 && flag; jj++)
                {
                    if(ii == jj) continue;

                    for(ll kk = 0; kk < 3 && flag; kk++)
                    {
                        if(ii == kk || jj == kk) continue;

//                        cout << vec[x][ii] << " " << vec[x][jj] << endl;

//                        cout << i << endl;
//                        cout << arr[top][ii + 1] << " " << arr[top][jj + 1] << endl;
//
                        if(vis[arr[top][ii + 1]] && vis[arr[top][jj + 1]] && vis[arr[top][kk + 1]]) continue;

                        if(arr[top][ii + 1] == ans[i] && arr[top][jj + 1] == ans[i - 1])
                        {
                            ans[i + 1] = arr[top][kk + 1];
                            flag = 0;

                            vis[ans[i + 1]] = 1;

                            break;
                        }
                    }
                }
            }
        }


    }

    for(i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }

        cout << endl;



}
