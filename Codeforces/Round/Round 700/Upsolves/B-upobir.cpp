#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

#ifdef LOCAL
#define Gene template< class
#define Rics printer& operator,
Gene c> struct rge
{
    c b, e;
};
Gene c> rge<c> range(c i, c j)
{
    return {i, j};
}
struct printer
{
    ~printer()
    {
        cerr<<endl;
    }
    Gene c >Rics(c x)
    {
        cerr<<boolalpha<<x;
        return *this;
    }
    Rics(string x)
    {
        cerr<<x;
        return *this;
    }
    Gene c, class d >Rics(pair<c, d> x)
    {
        return *this,"(",x.first,", ",x.second,")";
    }
    Gene ... d, Gene ...> class c >Rics(c<d...> x)
    {
        return *this, range(begin(x), end(x));
    }
    Gene c >Rics(rge<c> x)
    {
        *this,"[";
        for(auto it = x.b; it != x.e; ++it)
            *this,(it==x.b?"":", "),*it;
        return *this,"]";
    }
};
#define debug() cerr<<"LINE "<<__LINE__<<" >> ", printer()
#define dbg(x) "[",#x,": ",(x),"] "
#define tham getchar()
#endif

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

mt19937_64 rng((unsigned)chrono::system_clock::now().time_since_epoch().count());
//const ll mod = ;
//const ld error = ;
const ld PI = acosl(-1);

//const int/ll inf = ;
//const int nmax = ;
///===========================================  template  =======================================================

int main()
{
    FASTIO;

//        freopen("input.txt", "r", stdin);

    int n;
    while(cin >> n)
    {
        vector<int> input(n);

        for(int i = 0; i<n; i++) cin>>input[i];

        int a = -1, b = -1;

        int ans = 0;

        for(int i = 0; i<n; i++)
        {
            if(input[i] != a && input[i] != b)
            {
                if(i == n-1)
                    a = input[i], ans++;
                else
                {
                    if(a == input[i+1]) a = input[i], ans++;
                    else b = input[i], ans++;
                }
            }
            else if(input[i] != a)
            {
                a = input[i];
                ans++;
            }
            else if(input[i] != b)
            {
                b = input[i];
                ans++;
            }
        }

        cout<<ans<<endl;
    }
}
