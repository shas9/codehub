#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cassert>
#include <unordered_map>
#include <sys/resource.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define FOR(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)

using namespace std;

typedef long long ll;

const int mod = 3 * (1 << 18) + 1;

int mul(int a, int b) {
  return a * (ll) b % mod;
}

int add(int a, int b) {
  int res = a + b;
  if (res >= mod) res -= mod;
  if (res < 0) res += mod;
  return res;
}

int modpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

vector<int> getEvenPoly(vector<int> &poly) {
  vector<int> res;
  for (int i = 0; i < poly.size(); i += 2) res.push_back(poly[i]);
  return res;
}

vector<int> getOddPoly(vector<int> &poly) {
  vector<int> res;
  for (int i = 1; i < poly.size(); i += 2) res.push_back(poly[i]);
  return res;
}

int eval(vector<int> &poly, int x) {
  int ans = 0, cur = 1;
  for (int coeff : poly) {
    ans = add(ans, mul(coeff, cur));
    cur = mul(cur, x);
  }
  return ans;
}

int n = (1 << 18), g = 10, w = 1000, K = n;

vector<int> solve(vector<int> poly, vector<int> p) {
  vector<int> ans;

  if (p.size() <= 2) {
    REP(i, p.size()) ans.push_back(eval(poly, p[i]));
  } else {
    vector<int> pp;
    REP(i, p.size() / 2) pp.push_back(mul(p[i], p[i]));

    vector<int> L = solve(getEvenPoly(poly), pp);
    vector<int> R = solve(getOddPoly(poly), pp);

    REP(i, p.size()) {
      int idx = (i < p.size() / 2 ? i : i - p.size() / 2);
      int cur = add(L[idx], mul(p[i], R[idx]));
      ans.push_back(cur);
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int nn, k, x;
  cin >> nn;
  nn += 1;

  vector<int> poly(nn);
  REP(i, nn) cin >> poly[i];

  vector<int> p;
  REP(i, K) p.push_back(modpow(w, i));

  vector<int> ans(mod, -1);

  REP(add, 3) {
    vector<int> newPoly(nn);
    REP(i, nn) newPoly[i] = mul(poly[i], modpow(g, add * i));

    vector<int> temp_ans = solve(newPoly, p);
    REP(i, p.size()) {
      ans[mul(p[i], modpow(g, add))] = temp_ans[i];
    }
  }

  ans[0] = poly[0];

  cin >> k;
  while (k--) {
    cin >> x;
    cout << ans[x] << endl;
  }

  return 0;
}
