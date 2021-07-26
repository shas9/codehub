// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

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

using namespace std;

#define ll long long

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

class Solution
{
public:

#define ll int


    struct Hash
    {
        vector < ll > h1, h2;
        const ll MAX_N = 2500, mod = 2e9+63, base1 = 1e9+21, base2 = 1e9+181;
        vector < ll > pw1, pw2;

        void precalc()
        {
            pw1.resize(2500);
            pw2.resize(2500);

            pw1[0] = pw2[0] = 1;
            for(int i = 1; i < MAX_N; i++)
            {
                pw1[i] = (pw1[i-1] * 1LL * base1) % mod;
                pw2[i] = (pw2[i-1] * 1LL * base2) % mod;
            }
        }

        string s;

        void init(string t, bool x)
        {
			precalc();
            h1.resize(2500);
            h2.resize(2500);
            if(x) reverse(t.begin(), t.end());

            s = " ";

            for(auto it: t) s.push_back(it);

            ll slen = s.size();

//            cout << s << " " << t << endl;

            h1[0] = h2[0] = 0;
            for(int i = 1; i <= slen; i++)
            {
                h1[i] = (h1[i-1] * 1LL * base1 + s[i]) % mod;
                h2[i] = (h2[i-1] * 1LL * base2 + s[i]) % mod;
            }
        }

        inline long long hashVal(ll l, ll r)
        {
            ll hsh1 = (h1[r] - h1[l-1] * 1LL * pw1[r-l+1]) % mod;
            if(hsh1 < 0) hsh1 += mod;
            ll hsh2 = (h2[r] - h2[l-1] * 1LL * pw2[r-l+1]) % mod;
            if(hsh2 < 0) hsh2 += mod;

            return ((long long)hsh1 << 32) | hsh2;
        }

        inline ll hashOne(ll l, ll r)
        {
            ll hsh1 = (h1[r] - h1[l-1] * 1LL * pw1[r-l+1]) % mod;
            if(hsh1 < 0) hsh1 += mod;
            return hsh1;
        }

        inline ll hashTwo(ll l, ll r)
        {
            ll hsh2 = (h2[r] - h2[l-1] * 1LL * pw2[r-l+1]) % mod;
            if(hsh2 < 0) hsh2 += mod;
            return hsh2;
        }
    } fw, fw2;

    bool checkPartitioning(string s)
    {
        fw.init(s,0);
        fw2.init(s,1);

        ll n = s.size();

//        ll cnt = 0;

        for(ll i = 0, ii = n; i + 2 < n; i++, ii--)
        {
            for(ll j = i + 1, jj = ii - 1; j + 1 < n; j++, jj--)
            {
//				++cnt;
//                long long h11 = fw.hashVal(1, i + 1);
//                long long h12 = fw2.hashVal(ii, n);
//
//                long long h21 = fw.hashOne(i + 2, j + 1);
//                long long h22 = fw2.hashOne(jj, ii - 1);
//
//                long long h31 = fw.hashVal(j + 2, n);
//                long long h32 = fw2.hashVal(1, jj - 1);

				ll h11 = fw.hashOne(1, i + 1);
                ll h12 = fw2.hashOne(ii, n);

                ll h21 = fw.hashOne(i + 2, j + 1);
                ll h22 = fw2.hashOne(jj, ii - 1);

                ll h31 = fw.hashOne(j + 2, n);
                ll h32 = fw2.hashOne(1, jj - 1);

//                cout << 1 << " " << i + 1 << " % " << i + 2 << " " << j + 1 << " %% " << j + 2 << " " << n << "\n";
//
//                cout << h11 << " " << h12 << " & " << h21 << " " << h22 << " && " << h31 << " " << h32 << "\n";

                if(h11 == h12 && h21 == h22 && h31 == h32) return 1;
            }
        }

//        cout << cnt << "\n";

        return 0;
    }
};

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	string str;

	while(cin >> str)
	{
//		cout << str.size() << "\n";
		cout << checkPartitioning(str) << "\n";
	}


}



