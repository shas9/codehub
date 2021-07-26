#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#define long long long
using namespace std;
const int N=1e6,mod=998244353;
int phi[N+2];
void calPhi(void)
{
  for(int i=1;i<=N;i++)
  {
    phi[i]+=i;
    for(int j=i+i;j<=N;j+=i)phi[j]-=phi[i];
  }
}
int big(int b,int p)
{
  int r=1;
  while(p)
  {
    if(p&1)r=(1LL*r*b)%mod;
    b=(1LL*b*b)%mod;p/=2;
  }
  return r;
}
vector<int>d[N+2];
void divisors()
{
  for(int i=1;i<=N;i++)
  {
    for(int j=i;j<=N;j+=i)
      d[j].push_back(i);
  }
  for(int i=1;i<=N;i++)
    reverse(d[i].begin(),d[i].end());
}
long ans,cnt[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  calPhi();divisors();

  auto add=[&](int n)
  {
    for(auto x:d[n])
    {
      ans=(ans+cnt[x]*phi[x])%mod;
      cnt[x]++;
    }
  };
  auto rem=[&](int n)
  {
    for(auto x:d[n])
    {
      cnt[x]--;
      ans=(ans-cnt[x]*phi[x])%mod;
    }
  };

  int n;
  while(cin >> n)
  {
	ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(n % i == 0)
		{
			ans += phi[i];
		}
	}

	cout << ans << endl;
  }


  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;add(x);
  }
  int q;cin>>q;
  for(int i=1;i<=q;i++)
  {
    int ty,x;cin>>ty>>x;
    if(ty==1)add(x),n++;else rem(x),n--;

    cout << ans << endl;
    ans=(ans+mod)%mod;
    cout<<(1LL*ans*big(((1LL*n*(n-1))/2)%mod,mod-2))%mod<<endl;
  }
  return 0;
}
