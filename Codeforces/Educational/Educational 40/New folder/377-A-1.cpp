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

#define pll pair < ll, ll >
#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 1000

using namespace std;

ll r, c, k;

bool vis[maxn][maxn];
char mp[maxn][maxn];


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> r >> c >> k;

    for(i = 0; i < r; i++)
    {
        cin >> mp[i];
    }

    ll cnt = 0;
    ll cnt2 = 0;

    ll sr = -1, sc = -1;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(mp[i][j] == '.')
            {
                cnt++;

                sr = i;
                sc = j;

            }
        }
    }

    cnt -= k;

//    cout << cnt << endl;

    queue < pll > q;

    q.push(make_pair(sr,sc));
    cnt2 = 1;

    ll disx[] = {-1,1,0,0};
    ll disy[] = {0,0,1,-1};

    vis[sr][sc] = 1;
    while(!q.empty())
    {
        pll tmp = q.front();
        q.pop();

        ll tr = tmp.first;
        ll tc = tmp.second;

        for(i = 0; i < 4; i++)
        {
            ll tr_= tr + disx[i];
            ll tc_ = tc + disy[i];


            if(tr_ >= 0 && tr_ < r && tc_ >= 0 && tc_ < c && vis[tr_][tc_] == 0 && mp[tr_][tc_] == '.')
            {
                vis[tr_][tc_] = 1;
                cnt2++;

                q.push(make_pair(tr_,tc_));

                if(cnt2 > cnt)
                {
                    mp[tr_][tc_] = 'X';
                }
            }
        }
    }

    //bug;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            cout <<mp[i][j];
        }

        cout << endl;
    }


}


