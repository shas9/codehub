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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

ll hp[10][10];
//vector < pair < ll, ll > > v[10];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    //v.clear();

    for(i = 1; i <= 5; i++)
    {
        for(j = 1; j <= 5; j++)
        {
            slld(hp[i][j]);
        }
    }

    ll mx = -1;
    ll pos, x, y;
    for(i = 1; i <= 5; i++)
    {
        for(j = i + 1; j <= 5; j++)
        {
            ans = hp[i][j] + hp[j][i];
            for(k = 1; k <= 5; k++)
            {
                if(k == i || k == j) continue;

                ll temp = hp[i][k] + hp[k][i];

                for(m = 1; m <= 5; m++)
                {
                    if(m == i || m == j || m == k) continue;
                    ll temp3 = hp[i][m] +  hp[m][i];
                    for(n = 1; n <= 5; n++)
                    {
                        if(n == i || n == j || n == k || n == m) continue;

                        ll temp5 = hp[m][n] + hp[n][m];

                        if(mx < ((ans + temp) * 2) + temp3 + temp5)
                        {
                            mx = ((ans + temp) * 2) + temp3 + temp5;
                            cout << mx << endl;
                            cout << n << " " << m << " " << " " << i << " " << k << " " << j << endl;
                        }
                    }
                    ll temp4 = hp[j][m] +  hp[m][j];
                    for(n = 1; n <= 5; n++)
                    {
                        if(n == i || n == j || n == k || n == m) continue;

                        ll temp5 = hp[m][n] + hp[n][m];

                        if(mx < ((ans + temp) * 2) + temp4 + temp5)
                        {
                            mx = ((ans + temp) * 2) + temp4 + temp5;
                            cout << mx << endl;
                            cout << n << " " << m << " " << " " << j << " " << k << " " << i << endl;
                        }
                    }
                }

                ll temp2 = hp[j][k] + hp[k][j];

                for(m = 1; m <= 5; m++)
                {
                    if(m == i || m == j || m == k) continue;
                    ll temp3 = hp[i][m] +  hp[m][i];
                    for(n = 1; n <= 5; n++)
                    {
                        if(n == i || n == j || n == k || n == m) continue;

                        ll temp5 = hp[m][n] + hp[n][m];

                        if(mx < ((ans + temp2) * 2) + temp3 + temp5)
                        {
                            mx = ((ans + temp2) * 2) + temp3 + temp5;
                            cout << mx << endl;
                        }
                    }
                    ll temp4 = hp[j][m] +  hp[m][j];
                    for(n = 1; n <= 5; n++)
                    {
                        if(n == i || n == j || n == k || n == m) continue;

                        ll temp5 = hp[m][n] + hp[n][m];

                        if(mx < ((ans + temp2) * 2) + temp4 + temp5)
                        {
                            mx = ((ans + temp2) * 2) + temp4 + temp5;
                            cout << mx << endl;
                        }
                    }
                }
            }
        }
    }

//    ans = mx * 2;
//
//    bool on[10];
//
//    memset(on,false,sizeof on);
//
//    on[pos] = 1;
//    on[x] = 1;
//    on[y] = 1;
//
//    mx = -1;
//    ll p = 0;
//
//    for(i = 1; i < 6; i++)
//    {
//        if(on[i]) continue;
//        ll temp = hp[i][x] + hp[x][i];
//        ll temp2 = hp[i][pos] + hp[pos][i];
//
//        if(temp > mx)
//        {
//            mx = temp;
//            p = i;
//        }
//
//        if(temp2 > mx)
//        {
//            mx = temp2;
//            p = i;
//
//            swap(pos,x);
//        }
//    }
//
//    on[p] = 1;
//
//    ans += mx;
//
//    for(i = 1; i < 6; i++)
//    {
//        if(on[i]) continue;
//        ll temp = hp[i][p] + hp[p][i];
//
//        ans += temp;
//        break;
//
//    }

    cout << mx << endl;




}


