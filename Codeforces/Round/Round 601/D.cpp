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

char grid[105][105];
ll ans[105][105];
char ind[105];
ll freq[105];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    ll c;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(r);
        slld(c);
        slld(k);

        memset(freq,0,sizeof freq);

        ll cnt = 0;
        for(i = 1; i <= r; i++)
        {
            for(j = 1; j <= c; j++)
            {
                scanf(" %c", &grid[i][j]);

                if(grid[i][j] == 'R') cnt++;
            }
        }

        ll ff = cnt / k;
        ll ss = cnt % k;

        ll num = 1;
        for(i = 1; i <= r; i++)
        {
            if(i % 2)
            {
                for(j = c; j >= 1; j--)
                {
                    ans[i][j] = num;

                    if(grid[i][j] == 'R')
                    {
                        freq[num]++;
                        cnt--;

                        if(cnt == 0) continue;

                        if(freq[num] == ff)
                        {
                            if(ss)
                                ss--;
                            else
                                num++;
                        }
                        else if(freq[num] > ff)
                        {
                            num++;
                        }

                    }
                }
            }
            else
            {
                for(j = 1; j <= c; j++)
                {
                    ans[i][j] = num;

                    if(grid[i][j] == 'R')
                    {
                        freq[num]++;
                        cnt--;

                        if(cnt == 0) continue;

                        if(freq[num] == ff)
                        {
                            if(ss)
                                ss--;
                            else
                                num++;
                        }
                        else if(freq[num] > ff)
                        {
                            num++;
                        }
                    }
                }
            }
        }

        for(i = 0; i <= 9; i++)
        {
            ind[i + 1] = '0' + i;
        }

        for(i = 0; i <= 25; i++)
        {
            ind[i + 11] = 'a' + i;
        }

        for(i = 0; i <= 25; i++)
        {
            ind[i + 37] = 'A' + i;
        }

        for(i = 1; i <= r; i++)
        {
            for(j = 1; j <= c; j++)
            {
                cout << ind[ans[i][j]];
            }

            cout << endl;
        }




    }


}



