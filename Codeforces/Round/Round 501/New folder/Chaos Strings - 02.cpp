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

ll hashfunc(string &st)
{
    ll sz = st.size();

    ll flag = 0;

    ll i;

    for(i = 0; i < sz; i++)
    {
        flag *= 32;
        flag += (st[i] - 'a') + 1;
    }

    for(i = sz; i <= 10; i++)
    {
        flag *= 32;
    }

    return flag;
}

vector < pll > vec;
vector < ll > sec;
unordered_map < ll, ll > mp;
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    string x;

    pair < ll, ll > p;
    for(i = 0; i < n; i++)
    {
        cin >> x;

        p.first = hashfunc(x);

        reverse(x.begin(),x.end());

        p.second = hashfunc(x);

        vec.push_back(p);
        sec.push_back(p.second);
    }

    sort(vec.begin(),vec.end());
    sort(sec.begin(),sec.end());

    for(i = 0; i < n; i++) mp[sec[i]] = i + 1;

    ans = 0;

    update(mp[vec[0].second],1,n);

    for(i = 1; i < n; i++)
    {
        ll ind = mp[vec[i].second];

        ans += query(n);
        ans -= query(ind);

        update(ind,1,n);
    }

    plld(ans);
}


