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

string str;
set < char > st;
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
        cin >> str;

        st.clear();

        ll cnt = 1;

        for(i = 1; i < str.size(); i++)
        {
            if(i == 1)
            {
                if(str[i] != str[i - 1])
                {
                    st.insert((char)str[0]);
                    cnt = 1;
                }
            }

            if(str[i] == str[i - 1])
            {
                cnt++;
            }
            else
            {
                if(cnt % 2)
                st.insert((char)str[i - 1]);

                cnt = 1;
            }
        }

        if(str.size() == 1)
        {
            st.insert(str[0]);
        }

        if(cnt % 2)
            st.insert((char)str[str.size() - 1]);

        set < char > :: iterator it;

        for(it = st.begin(); it != st.end(); it++)
        {
            cout << *it;
        }

        cout << endl;
    }


}



