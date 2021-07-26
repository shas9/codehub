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

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359


using namespace std;

char path[55][55] = {};
ll m, n, ans;
char code[110];
char dirx[4];
ll i, j, tag, ftag;

char arr[] = "UDLR";

/*void go(ll x, ll y, ll pos)
{
    if(path[x][y] == 'E')
    {
        tag = 1;
        return;
    }

    if(x >= n || y >= m)
    {
        return;
    }

    if(x < 0 || y < 0)
    {
        return;
    }

    if(path[x][y] == '#')
    {
        return;
    }

    if(dirx[code[pos] - 48] == 'U')
    {
        go(x-1,y,pos+1);
    }
    else if(dirx[code[pos] - 48] == 'D')
    {
        go(x+1,y,pos+1);
    }
    else if(dirx[code[pos] - 48] == 'R')
    {
        go(x,y+1,pos+1);
    }
    else if(dirx[code[pos] - 48] == 'L')
    {
        go(x,y-1,pos+1);
    }
}*/

ll fx, fy;

ll go()
{
    ll x = fx;
    ll y = fy;

    for(ll pos = 0; pos < strlen(code); pos++)
    {
        int z = code[pos] - 48;

        //cout << z << endl;
        if(dirx[z] == 'U')
        {
            x -= 1;
        }
        else if(dirx[z] == 'D')
        {
            x += 1;
        }
        else if(dirx[z] == 'R')
        {
            y += 1;
        }
        else if(dirx[z] == 'L')
        {
            y -= 1;
        }

        //cout << x << " " << y << endl;



        if(path[x][y] == 'E')
        {
            //bug;
            return 1;
        }
        else if(x >= n || y >= m)
        {
            //cout << x << " " << y << endl;

            //bug;
            return 0;
        }
        else if(x < 0 || y < 0)
        {
            //bug;
            return 0;
        }
        else if(path[x][y] == '#')
        {
            //bug;
            return 0;
        }
    }

    return 0;

}


int main()
{
    ll k, l, o, p, q;
    ll testcase;
    ll input, flag;

    cin >> n >> m;

    ans = 0;


    for(ll cs = 0; cs < n; cs++)
    {
        cin >> path[cs];
    }

    cin >> code;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(path[i][j] == 'S')
            {
                fx = i;
                fy = j;
                //cout << i << "               " << j << endl;
            }
        }
    }

    //cout << fx << "      --         " << fy << endl;
    for(k = 0; k < 4; k++)
    {
        for(l = 0; l < 4; l++)
        {
            if(k != l)
            {
                for(p = 0; p < 4; p++)
                {
                    if(p != k && p != l)
                    {
                        for(q = 0; q < 4; q++)
                        {
                            if(q != p && q != k && q != l)
                            {
                                dirx[0] =arr[k];
                                dirx[1] =arr[l];
                                dirx[2] =arr[p];
                                dirx[3] =arr[q];

                                //cout << dirx << " Fx: " << fx << " Fy: " << fy << endl;
                                ans += go();

                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
}


