// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 958585860497

#define base 2001487

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

string solve(ll k)
{
    sort(str.begin(),str.end());

    ll len = str.size() - 1;

    string ret = "";

    ll freq[30];
    memset(freq,0,sizeof freq);

    set < ll > st;

    for(auto it: str)
    {
        freq[it - 'a']++;

        st.insert(it - 'a');
    }

    if(str[k - 1] != str[0])
    {
        ret += str[k - 1];

        return ret;
    }

    if(st.size() == 1)
    {
        for(auto it: st)
        {
            ll x = freq[it] / k;

            if(freq[it] % k) x++;

            for(ll i = 0; i < x; i++) ret += (it + 'a');
        }

        return ret;
    }

    if(st.size() == 2)
    {
        set < ll > :: iterator it, jt;

        it = st.begin();
        jt = it;
        jt++;

        if(freq[*it] == k && freq[*jt] == k)
        {
            ret += (*it + 'a');
            ret += (*jt + 'a');

            return ret;
        }

        if(freq[*it] == k)
        {
			ret += (*it + 'a');

			ll x = freq[*jt] / k;

			if(freq[*jt] % k) x++;

			while(x--) ret += (*jt + 'a');

			return ret;
        }
    }


    for(ll i = k - 1; i <= len; i++)
    {
        ret += str[i];
    }

    return ret;

}

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
        slld(n);
        slld(k);

        cin >> str;

        string out = solve(k);

        cout << out << "\n";
    }


}



