#include <bits/stdc++.h>

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

struct node
{
    ll x, y, z, id;
};

node arr[100005];

bool comp(node a, node b)
{
    if(a.z != b.z) return a.z < b.z;

    if(a.y != b.y) return a.y < b.y;

    return a.x < b.x;
}

vector < node > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, q;

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i].x);
        slld(arr[i].y);
        slld(arr[i].z);

        arr[i].id = i;
    }

    sort(arr + 1, arr + 1 + n, comp);

    node backup;
    bool on = 0;

//    for(i = 1; i <= n; i++)
//    {
//        cout << arr[i].x << " " << arr[i].y << " " << arr[i].z << " " << arr[i].id << endl;
//    }

    for(i = 1; i < n; i++)
    {
        if(arr[i].z != arr[i + 1].z)
        {
            vec.push_back(arr[i]);

            if(i == n - 1)
            {
                vec.push_back(arr[i + 1]);
            }
            continue;
        }

        if(arr[i].y != arr[i + 1].y)
        {
            if(on)
            {
                on = 0;
                cout << backup.id << " " << arr[i].id << endl;
            }
            else
            {
                backup = arr[i];
                on = 1;

                if(i == n - 1) vec.push_back(arr[i + 1]);
            }
            continue;
        }

        cout << arr[i].id << " " << arr[i + 1].id << endl;
        i++;

        if(i == n - 1)
        {
            if(on)
            {
                on = 0;
                cout << backup.id << " " << arr[i].id << endl;
            }
            else
            {
                backup = arr[i];
                on = 1;
            }
        }
    }

    if(vec.size())
    for(i = 0; i < vec.size() - 1; i += 2)
    {
        cout << vec[i].id << " " << vec[i + 1].id << endl;
    }

    if(on)
    {
        cout << vec[vec.size() - 1].id << " " << backup.id << endl;
    }

    return 0;


}


