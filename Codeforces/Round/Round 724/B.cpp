// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

const ll MAX_N = 1e6+10, mod = 2e9+63, base1 = 1e9+21, base2 = 1e9+181;
char s[MAX_N];  // 1-indexed
ll pw1[MAX_N], pw2[MAX_N];

void precalc() {
    pw1[0] = pw2[0] = 1;
    for(int i = 1; i < MAX_N; i++) {
        pw1[i] = (pw1[i-1] * base1) % mod;
        pw2[i] = (pw2[i-1] * base2) % mod;
    }
}

struct Hash {
    ll h1[MAX_N], h2[MAX_N];

    void init(ll slen) {
        h1[0] = h2[0] = 0;
        for(int i = 1; i <= slen; i++) {
            h1[i] = (h1[i-1] * base1 + s[i]) % mod;
            h2[i] = (h2[i-1] * base2 + s[i]) % mod;
        }
    }

    inline ll hashVal(int l, int r) {
        ll hsh1 = (h1[r] - h1[l-1] * pw1[r-l+1]) % mod;
        if(hsh1 < 0) hsh1 += mod;
        ll hsh2 = (h2[r] - h2[l-1] * pw2[r-l+1]) % mod;
        if(hsh2 < 0) hsh2 += mod;
        return (hsh1 << 32) | hsh2;
    }

    inline ll hashOne(int l, int r) {
        ll hsh1 = (h1[r] - h1[l-1] * pw1[r-l+1]) % mod;
        if(hsh1 < 0) hsh1 += mod;
        return hsh1;
    }

    inline ll hashTwo(int l, int r) {
        ll hsh2 = (h2[r] - h2[l-1] * pw2[r-l+1]) % mod;
        if(hsh2 < 0) hsh2 += mod;
        return hsh2;
    }
} fw;

/* call pw_calc() for calculating powers less than MAX_N
 * slen = strlen(s+1);   --> string length
 * fw.init() will calculate the double hashes
 * fw.hashVal(l,r) will return [l,,r] merged double hash value
 * fw.hashOne(l, r) will return [l,,r] base1 hash
 * fw.hashTwo(l, r) will return [l,,r] base2 hash
*/

map < ll, ll > mp;

string str;

Hash h1;

void solve()
{
    for(ll i = 0; i < 26; i++)
    {
        s[1] = i + 'a';

        h1.init(1);

        ll h = h1.hashVal(1,1);

//        cout << i << " " << h << "\n";

        if(mp.find(h) == mp.end())
        {
            str += i + 'a';

            return;
        }
    }

//    bug(2);

    for(ll i = 0; i < 26; i++)
    {
        for(ll j = 0; j < 26; j++)
        {
            s[1] = i + 'a';
            s[2] = j + 'a';

            h1.init(2);

            ll h = h1.hashVal(1,2);

            if(mp.find(h) == mp.end())
            {
                str = i + 'a';
                str += j + 'a';
                return;
            }
        }
    }

//    bug(3);

    for(ll k = 0; k < 26; k++)
    {
        for(ll i = 0; i < 26; i++)
        {
            for(ll j = 0; j < 26; j++)
            {
                s[1] = k + 'a';
                s[2] = i + 'a';
                s[3] = j + 'a';

                h1.init(3);

                ll h = h1.hashVal(1,3);

                if(mp.find(h) == mp.end())
                {
                    str = k + 'a';
                    str += i + 'a';
                    str += j + 'a';
                    return;
                }
            }
        }
    }

    assert(0);

    return;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    precalc();

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        mp.clear();
        cin >> n;
        cin >> s + 1;

        fw.init(n);

//        bug(1);

        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= n; j++)
            {
//                if(i == j)
//                {
//                    if(s[i] == 'a') cout << fw.hashVal(i,j) << " ++ " <<  endl;
//                }
                mp[fw.hashVal(i,j)] = 1;
            }
        }

//        bug(2);

        str = "";

//        bug(3);

        solve();

        cout << str << "\n";
    }


}


