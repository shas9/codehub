// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll int
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define inf (1LL << 61)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// === Debug macro starts here ===
#ifndef ONLINE_JUDGE
#define DEBUG
#define SYS_COL system("COLOR")
#endif

int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; SYS_COL; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}
// === Debug macro ends here ===

#define ff first
#define ss second

const ll lim = 1<<16, MAX_N = 16;
ll nxt[lim], att[MAX_N], n, m, k, mx;
vector <ll> g[MAX_N], ans[110];

bitset <lim> vis[20], dp[110][MAX_N], check[110][MAX_N];

bool solve(ll msk, ll rem, ll step)
{
    if(msk==0)
        return 1;
    if(step == 100)
        return 0;

    bitset <lim> &ret = dp[step][rem];
    bitset <lim> &chk = check[step][rem];
    if(chk[msk])
        return ret[msk];

    //cerr << nxt[msk] << " " << rem << " " << step << endl;
    chk[msk] = 1, ret[msk] = 0;

    if(rem != 0) {
        for0(i, n) {
            if((msk>>i) & 1) {
                ret[msk] = solve(msk^(1<<i), rem-1, step);
                if(ret[msk]) return 1;
            }
        }
        return ret[msk];
    }

    return ret[msk] = solve(nxt[msk], k, step+1);
}

void get_ans(ll msk, ll rem, ll step)
{
    if(msk==0)
        return;
    mx = max(mx, step);

    if(rem != 0) {
        for0(i, n) {
            if((msk>>i) & 1) {
                bool got = solve(msk^(1<<i), rem-1, step);

                if(got) {
                    ans[step].pb(i);
                    get_ans(msk^(1<<i), rem-1, step);
                    return;
                }
            }
        }
    }

    get_ans(nxt[msk], k, step+1);
}

int main()
{
    fastio;
    cin >> n >> m >> k;

    for0(i, m) {
        ll u, v;
        cin >> u >> v;

        u--, v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    for0(i, n) {
        for(ll &v : g[i])
            att[i] |= (1<<v);
    }

    ll lim = 1<<n;
    for0(i, lim) {
        ll msk = 0;

        for0(j, n) {
            if((i>>j) & 1)
                msk |= att[j];
        }
        nxt[i] = msk;
    }

    ll ret = solve(lim-1, k, 0);
    //dbg(ret);

    if(!ret) {
        cout << -1 << EL;
        return 0;
    }

    get_ans(lim-1, k, 0);

    cout << mx+1 << EL;
    for(ll i = 0; i <= mx; i++) {
        for(ll j = 0; j < ans[i].size(); j++) {
            cout << (char)('a'+ans[i][j]);
        }
        cout << EL;
    }

    return 0;
}

