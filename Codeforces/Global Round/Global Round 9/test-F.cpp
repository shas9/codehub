#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

#define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
#define hoise cerr<<"hoise - "<<__LINE__<<"\n"
#define tham getchar()
mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 500+10;

#define contents(T, c) ostream_iterator<T>(cerr, c)
///===========================================  template  =======================================================
ll a[4];

int query(ll y){
    cout<<y<<endl;
    int x;
    cin>>x;
    a[x] += y;
    return x;
}

int main(){


    cin>>a[1]>>a[2]>>a[3];
    vector<int> v{1, 2, 3};
    cout<<"First"<<endl;

    int last = -1;
    bool locked = false;;
    while(true){
        //cout<<"d "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
        sort(v.begin(), v.end(), [&](int i, int j){
             return a[i] < a[j];});

        if(last == v[2]){
            if(!locked){
                ll y = a[v[2]] - a[v[0]] + a[v[2]] - a[v[1]];
                int x = query(y);
                locked = true;
                last = x;
            }
            else{
                ll y = a[v[1]] - a[v[0]];
                int x = query(y);
                assert(x == 0);
                return 0;
            }
        }
        else{
            ll y = a[v[2]] - a[v[0]]+1;
            int x = query(y);
            last = x;
        }
    }

    return 0;
}
