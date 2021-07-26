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

vector < pll > vec;
vector < ll > zero;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n)
    {
        vec.clear();
        zero.clear();

        ll neg = 0;
        for(i = 1; i <= n; i++)
        {
            slld(input);


            if(input != 0)
            vec.push_back(make_pair(input,i));

            if(input < 0) neg++;
            if(input == 0) zero.push_back(i);
        }

        sort(vec.begin(),vec.end());

        ll sz = zero.size();

        for(i = 1; i < sz; i++)
        {
            cout << 1 << " " << zero[i - 1] << " " << zero[i] << endl;
        }
        if(neg % 2)
        {
            cout << 2 << " " << vec[0].second << endl;
            if(vec.size() > 1 && zero.size()) cout << 1 << " " << zero[sz - 1] << " " << vec[1].second << endl;
        }
        else if(zero.size() && vec.size())
        {
            cout << 2 << " " << zero[sz - 1] << endl;
        }

        i = 1;
        if(neg % 2) i = 2;


        for(; i < vec.size(); i++)
        {
            cout << 1 << " " << vec[i - 1].second << " " << vec[i].second << endl;
        }

    }


}


