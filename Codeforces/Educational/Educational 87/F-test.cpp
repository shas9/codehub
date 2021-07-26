#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 100;

int n, k;
pair<pt, int> a[N];

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	forn(i, n){
		scanf("%d%d", &a[i].x.x, &a[i].x.y);
		a[i].y = i;
	}
	return true;
}

int dp[N][N];
int p[N][N];

void solve() {
	sort(a, a + n, [](const pair<pt, int> &a, const pair<pt, int> &b){
		if (a.x.y != b.x.y)
			return a.x.y < b.x.y;
		return a.x.x < b.x.x;
	});

	forn(i, N) forn(j, N)
		dp[i][j] = -INF;
	dp[0][0] = 0;
	forn(i, n) forn(j, N) if (dp[i][j] >= 0){
		if (dp[i + 1][j] < dp[i][j] + a[i].x.y * (k - 1)){
			dp[i + 1][j] = dp[i][j] + a[i].x.y * (k - 1);
			p[i + 1][j] = j;
		}
		if (dp[i + 1][j + 1] < dp[i][j] + a[i].x.y * j + a[i].x.x){
			dp[i + 1][j + 1] = dp[i][j] + a[i].x.y * j + a[i].x.x;
			p[i + 1][j + 1] = j;
		}
	}

	vector<int> ans1, ans2;
	int cur = k;
	for (int i = n; i > 0; --i){
		if (p[i][cur] == cur)
			ans2.pb(a[i - 1].y + 1);
		else
			ans1.pb(a[i - 1].y + 1);
		cur = p[i][cur];
	}

	for(int i = 0; i < n; i++)
	{
		cout << a[i].y << " " << a[i].x.x << " " << a[i].x.y << endl;
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cout << i << " " << j << ": " <<  dp[i][j] << " " << p[i][j] << endl;
		}
	}

	reverse(all(ans1));
	reverse(all(ans2));
	printf("%d\n", sz(ans1) + sz(ans2) * 2);
	forn(i, sz(ans1) - 1)
		printf("%d ", ans1[i]);
	for (auto it : ans2)
		printf("%d %d ", it, -it);
	printf("%d\n", ans1.back());
}

int main() {
//#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int tt = clock();

//#endif

	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	int tc;
	scanf("%d", &tc);
	while(tc--) {
		read();
		solve();

#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}
