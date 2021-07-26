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

map < string, string > mp;

void precalc()
{
    mp.clear();

    mp["iu"] = "q";
    mp["en"] = "f";
    mp["ei"] = "w";
    mp["eng"] = "g";
    mp["ang"] = "h";
    mp["uan"] = "r";
    mp["an"] = "j";
    mp["ue"] = "t";
    mp["uai"] = "k";
    mp["ing"] = "k";
    mp["un"] = "y";
    mp["uang"] = "l";
    mp["iang"] = "l";
    mp["sh"] = "u";
    mp["ou"] = "z";
    mp["ch"] = "i";
    mp["ia"] = "x";
    mp["ua"] = "x";
    mp["uo"] = "o";
    mp["ao"] = "c";
    mp["ie"] = "p";
    mp["zh"] = "v";
    mp["ui"] = "v";
    mp["in"] = "b";
    mp["ong"] = "s";
    mp["iong"] = "s";
    mp["iao"] = "n";
    mp["ai"] = "d";
    mp["ian"] = "m";

}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    precalc();

    string s;

    while(getline(cin, s))
    {
        string ss;

        stringstream str(s);

        while(str >> ss)
        {
            if(ss.size() == 1) cout << ss << ss << " ";
            else if(ss.size() == 2) cout << ss << " ";
            else if(mp.find(ss) != mp.end()) cout << ss.front() << mp[ss] << " ";
            else
            {
                string u = ss;
                string v = ss;

                while(u.size() > 1) u.pop_back();

                v.erase(v.begin());

                while(!v.empty())
                {
                    if(u.size() == 1 && mp.find(v) != mp.end())
                    {
                        cout << u << mp[v] << " ";
                        break;
                    }
                    else if(v.size() == 1 && mp.find(u) != mp.end())
                    {
                        cout << mp[u] << v << " ";
                        break;
                    }
                    else if(mp.find(u) != mp.end() && mp.find(v) != mp.end())
                    {
                        cout << mp[u] << mp[v] << " ";
                        break;
                    }

                    u += v.front();
                    v.erase(v.begin());
                }
            }
        }

        cout << "\n";
    }


}

