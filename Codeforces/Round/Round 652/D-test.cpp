/* In the name of Allah */

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mod = 1000000007;

ll p[2000005];
ll ans[2000005];

int main()
{
  p[0] = 0;
  p[1] = 1;
  for(int i = 2; i < 2000005; i++)
    p[i] = (p[i-2]*2 + p[i-1])%mod;

  ans[0] = 0;
  ans[1] = 0;
  ans[2] = 0;

  for(int i = 3; i < 2000005; i++)
    ans[i] = (ans[i-3] + p[i-2])%mod;

  // for(int i = 0; i < 10; i++)
  //   cout << p[i] << "**";

  int t;
  cin >> t;
  while(t--){
    ll n;
    cin >> n;
    if(n<2) cout << 0 << "\n";
    else
      cout << (ans[n]*4)%mod << "\n";
  }

  return 0;
}
