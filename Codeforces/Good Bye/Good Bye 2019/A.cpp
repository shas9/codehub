#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

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

vector < ll > vec1, vec2;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        vec1.clear();
        vec2.clear();

        slld(n);
        slld(m);
        slld(k);

        for(i = 0; i < m; i++)
        {
            slld(input);

            vec1.push_back(input);
        }


        for(i = 0; i < k; i++)
        {
            slld(input);
            vec2.push_back(input);
        }

        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());

        if(vec2[k - 1] >= vec1[m - 1]) cout << "NO" <<endl;
        else cout << "YES" << endl;
    }


}


