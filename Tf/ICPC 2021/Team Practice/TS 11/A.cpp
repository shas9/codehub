// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
#define eps 1e-9

const ll sz = 1e5 + 10;
char s[10];

double solve(double res, ll w)
{
    double lo = 0, hi = 1e12, ret = 0;
    ll cnt = 200;

    while(cnt--) {
        double mid = (lo+hi) / 2;

        double hap = log(1+mid/w);

        if(abs(hap-res) <= eps)
            ret = mid;

        if(hap < res)
            lo = mid;
        else
            hi = mid;
    }

    return ret;
}


int main()
{
    ll n, w;
    cin >> n >> w;

    double res = 0, prv = 1, p;
    ll val, safe = 0;
    double ans = 0;

    for1(i, n) {
        scanf("%s %lf %lld", s+1, &p, &val);

        double lose = 1-p;
        double losev = (lose*prv) * log(1+(double)safe/w);
        res += losev;

        ans = max(ans, solve(losev,w));

        double now = p*prv;
//        if(i != n) now *= 0.5;
        res += now * log(1+(double)val/w);

        ans = max(ans, solve(now * log(1+(double)val/w),w));

        prv = now * 0.5;
        if(s[1] == 's') safe = val;
    }

    dbg(res);
    dbg(log(1+(double)2316.82/w));


    printf("$%0.2f\n", ans);

    return 0;
}
