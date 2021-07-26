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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

unordered_map < ll, ll > mp1, mp2;
vector < string > vec;
char str[20];
ll hashof[100005];
ll tree[100005];

ll query(ll idx)
{
       ll sum=0;
       while(idx>0){
             sum+=tree[idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(ll idx, ll x, ll n) //n is the size of the array, x is the number to add
{
       while(idx<=n)
       {
             tree[idx]+=x;
             idx += idx & (-idx);
       }
}

ll hashfunc(ll ind)
{
    ll flag = 0;

    ll sz = vec[ind].size();

    for(ll i = 0; i < sz; i++)
    {
        flag *= 30;
        flag += (vec[ind][i] - 'a') + 1;
    }

    return flag;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    string x;

    for(i = 1; i <= n; i++)
    {
        scanf(" %s", str);

        ll len = strlen(str);

        x = "";

        for(j = 0; j < len; j++)
        {
            x += str[j];
        }

        vec.push_back(x);
    }

    sort(vec.begin(),vec.end());

    for(i = 0; i < n; i++)
    {
//        cout << vec[i] << " ";
        reverse(vec[i].begin(),vec[i].end());
//        cout << vec[i] << endl;
    }

    for(i = 0; i < n; i++)
    {
        flag = hashfunc(i);

        hashof[i + 1] = flag;
        mp1[i + 1] = flag;

        cout << vec[i] << " " << flag << endl;
    }

    sort(hashof + 1, hashof + 1 + n);

    for(i = 1; i <= n; i++) mp2[hashof[i]] = i;

    update(mp2[mp1[1]],1,n);

    ans = 0;
    for(i = 2; i <= n; i++)
    {
        ll ind = mp2[mp1[i]];

        ans += query(n);
        ans -= query(ind);

        update(ind,1,n);

    }

    plld(ans);


}


