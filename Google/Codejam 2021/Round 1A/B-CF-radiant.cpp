#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "rfd_wrap.h"
#endif

typedef long long ll;
typedef pair<int, int> pii;

#define bt(x) (1LL << (x))
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int inf = 0x3f3f3f3f;
const ll INF = 2e18;

const int N = 2 * 1024 + 7;

bool vis[N];
int lpair[N], rpair[N];
vector<int> adj[N];

bool bpm(int u) {
	for(int v : adj[u]) {
		if(vis[v]) continue;
		vis[v] = true;
		if(lpair[v] == -1 or bpm(lpair[v])) {
			lpair[v] = u;
			rpair[u] = v;
			return true;
		}
	}
	return false;
}

vector < int > vecset(int mask) {
	vector<int> ret;
	for(int i=0; (1<<i)<=mask; ++i) {
		if(mask & (1 << i)) ret.push_back(i);
	}
	return ret;
}

int main() {
	FastIO;

	int d, n;
	cin >> d >> n;

	vector<int> mask(n, 0);
	for(int i=0; i<n; ++i) {
		string s;
		cin >> s;
		reverse(all(s));
		for(char c : s) {
			mask[i] <<= 1;
			mask[i] ^= (c - '0');
		}
	}
	sort(all(mask), [](int& p, int& q) { return __builtin_popcount(p) > __builtin_popcount(q); });

	for(int i=0; i<n+n; ++i) {
		adj[i].clear();
		lpair[i] = -1, rpair[i] = -1;
	}

	for(int i=0; i<n; ++i) {
		for(int j=i+1; j<n; ++j) {
			if((mask[j] & mask[i]) == mask[j]) {
				adj[j].push_back(i);
			}
		}
	}

	vector < bool > used1(n, false);

    for (int v = 0; v < n; ++v)
    {
        for (int to : adj[v])
        {
            if (lpair[to] == -1)
            {
                lpair[to] = v;
                rpair[v] = to;

                used1[v] = true;
                break;
            }
        }
    }

	for(int i=0; i<n; ++i) {

        if(used1[i]) continue;
		fill(vis, vis + n + n, false);
		bpm(i);
	}

	fill(vis, vis + n, false);
	vector<int> res;

	for(int i=n-1; i>=0; --i) {
		if(vis[i]) continue;
		vis[i] = true;

		auto vini = vecset(mask[i]);
		res.insert(res.end(), all(vini));

		int cur = i;
		while(rpair[cur] != -1) {
			int emask = mask[cur] ^ mask[rpair[cur]];
			auto evec = vecset(emask);
			res.insert(res.end(), all(evec));
			cur = rpair[cur];
			vis[cur] = true;
		}

		res.push_back(-1);
	}
	res.pop_back();

	cout << (int) res.size() << "\n";
	for(int i=0; i<(int) res.size(); ++i) {
		if(i) cout << " ";
		if(res[i] == -1) cout << "R";
		else cout << res[i];
	} cout << "\n";

	return 0;
}
