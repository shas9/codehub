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

#define mod 1000000009


using namespace std;

vector < ll > graph[10];
vector < ll > dist[10];

//ll bfs(ll u, ll v)
//{
//    queue < ll > q;
//
//    q.push(u);
//
//    while(!q.empty())
//    {
//        ll top =
//    }
//}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;


    for(i = 1; i <= 5; i ++)
    {
        graph[i].clear();
        dist[i].clear();
    }

    graph[1].pb(2);
    dist[1].pb(200);

    graph[1].pb(3);
    dist[1].pb(300);

    graph[2].pb(4);
    dist[2].pb(3000);

    graph[2].pb(5);
    dist[2].pb(8000);

    graph[5].pb(2);
    dist[5].pb(8000);

    graph[4].pb(2);
    dist[4].pb(3000);

    graph[2].pb(1);
    dist[2].pb(200);

    graph[3].pb(1);
    dist[3].pb(300);

    slld(testcase);

    string in, out;
    ll u, v;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> in >> out;

        if(in == "Dhaka")
        {
            u = 1;
        }
        else if(in == "Chittagong")
        {
            u = 2;
        }
        else if(in == "Rajshahi")
        {
            u = 3;
        }
        else if(in == "Kathmandu")
        {
            u = 4;
        }
        else if(in == "Butwal")
        {
            u = 5;
        }

        if(out == "Dhaka")
        {
            v = 1;
        }
        else if(out =="Chittagong")
        {
            v = 2;
        }
        else if(out =="Rajshahi")
        {
            v = 3;
        }
        else if(out == "Kathmandu")
        {
            v = 4;
        }
        else if(out == "Butwal")
        {
            v = 5;
        }

        if(u == 1)
        {
            if(v == 2)
            {
                ans = 200;
            }
            else if(v == 3)
            {
                ans = 300;
            }
            else if(v == 4)
            {
                ans = 3200;
            }
            else if(v == 5)
            {
                ans = 8200;
            }
        }

        else if(u == 2)
        {
            if(v == 1)
            {
                ans = 200;
            }
            else if(v == 3)
            {
                ans = 500;
            }
            else if(v == 4)
            {
                ans = 3000;
            }
            else if(v == 5)
            {
                ans = 8000;
            }
        }

        else if(u == 3)
        {
            if(v == 2)
            {
                ans = 500;
            }
            else if(v == 1)
            {
                ans = 300;
            }
            else if(v == 4)
            {
                ans = 3200 + 300;
            }
            else if(v == 5)
            {
                ans = 8200 + 300;
            }
        }

        else if(u == 4)
        {
            if(v == 2)
            {
                ans = 3000;
            }
            else if(v == 3)
            {
                ans = 3500;
            }
            else if(v == 1)
            {
                ans = 3200;
            }
            else if(v == 5)
            {
                ans = 11000;
            }
        }

        else if(u == 5)
        {
            if(v == 2)
            {
                ans = 8000;
            }
            else if(v == 3)
            {
                ans = 8500;
            }
            else if(v == 4)
            {
                ans = 11000;
            }
            else if(v == 1)
            {
                ans = 8200;
            }
        }

        cout << ans << endl;
    }


}


