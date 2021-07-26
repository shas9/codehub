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

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    set < ll > st;

    ll arr[1000];
    st.clear();

    slld(testcase);
    slld(k);
    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> input;

        st.insert(input);

        arr[input] = cs;
    }

    if(st.size() < k)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    set < ll > :: iterator it;

    for(it = st.begin(); it != st.end() && k; --k, ++it)
    {
        cout << arr[*it] << " ";
    }


}
