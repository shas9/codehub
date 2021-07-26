#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define sci(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define scd(x) scanf("%lf",&x)

#define pfi(x) printf("%d",x)
#define pfl(x) printf("%lld",x)
#define pfd(x) printf("%lf",x)
#define pfc(x) printf("Case %d: ",x++)
#define ps printf(" ")
#define pn printf("\n")

#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define pf(x) push_front(x)
#define ppf(x) pop_front(x)
#define in(x,y) insert({x,y})
#define sv(a) sort(a.begin(),a.end())

bool nP[100001];
vector<int>primes;
void sieve(int n)
{
	int lim=sqrt(n);
	for(int i=2;i<=lim;i++)
	{
		if(!nP[i])
		{
			for(int j=i+i;j<=n;j+=i)
				nP[j]=true;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(!nP[i])
		{
			primes.pb(i);
		}
	}
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll p,y;
    cin>>p>>y;


    sieve(100000);

    for(ll i=y;i>p;i--)
    {
    	int j=0;
    	ll lim=sqrt(i);
        lim=min(p,lim);
    	ll n=i;

    	while(primes[j]<=lim)
    	{
    		while(n%primes[j]==0)
    		{
    			n/=primes[j];
                break;
    		}
            if(i!=n)
                break;
    		j++;
    	}
    	if(n==i && n>p)
    	{
    		cout<<n;
    		return 0;
    	}
    }
    cout<<-1;
    return 0;
}
