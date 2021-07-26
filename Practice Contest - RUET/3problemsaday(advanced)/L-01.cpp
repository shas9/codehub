// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

// Implementation of min cost max flow algorithm using adjacency
// matrix (Edmonds and Karp 1972).  This implementation keeps track of
// forward and reverse edges separately (so you can set cap[i][j] !=
// cap[j][i]).  For a regular max flow, set all edge costs to 0.
//
// Running time, O(|V|^2) cost per augmentation
//     max flow:           O(|V|^3) augmentations
//     min cost max flow:  O(|V|^4 * MAX_EDGE_COST) augmentations
//
// INPUT:
//     - graph, constructed using AddEdge()
//     - source
//     - sink
//
// OUTPUT:
//     - (maximum flow value, minimum cost value)
//     - To obtain the actual flow, look at positive values only.


const ll INF = numeric_limits< ll >::max() / 4;

struct MinCostMaxFlow
{
    int N;
    vector < vector < ll > > cap, flow, cost;
    vector < int > found;
    vector < ll > dist, pi, width;
    vector < pair < int, int > > dad;

    MinCostMaxFlow(int N) :
        N(N), cap(N, vector < ll > (N)), flow(N, vector < ll > (N)), cost(N, vector < ll > (N)),
        found(N), dist(N), pi(N), width(N), dad(N) {}

    void AddEdge(int from, int to, ll cap, ll cost)
    {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
    }

    void Relax(int s, int k, ll cap, ll cost, int dir)
    {
        ll val = dist[s] + pi[s] - pi[k] + cost;
        if (cap && val < dist[k])
        {
            dist[k] = val;
            dad[k] = make_pair(s, dir);
            width[k] = min(cap, width[s]);
        }
    }

    ll Dijkstra(int s, int t)
    {
        fill(found.begin(), found.end(), false);
        fill(dist.begin(), dist.end(), INF);
        fill(width.begin(), width.end(), 0);
        dist[s] = 0;
        width[s] = INF;

        while (s != -1)
        {
            int best = -1;
            found[s] = true;
            for (int k = 0; k < N; k++)
            {
                if (found[k]) continue;
                Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
                Relax(s, k, flow[k][s], -cost[k][s], -1);
                if (best == -1 || dist[k] < dist[best]) best = k;
            }
            s = best;
        }

        for (int k = 0; k < N; k++)
            pi[k] = min(pi[k] + dist[k], INF);
        return width[t];
    }

    pair< ll, ll > GetMaxFlow(int s, int t)
    {
        ll totflow = 0, totcost = 0;
        while (ll amt = Dijkstra(s, t))
        {
            totflow += amt;
            for (int x = t; x != s; x = dad[x].first)
            {
                if (dad[x].second == 1)
                {
                    flow[dad[x].first][x] += amt;
                    totcost += amt * cost[dad[x].first][x];
                }
                else
                {
                    flow[x][dad[x].first] -= amt;
                    totcost -= amt * cost[x][dad[x].first];
                }
            }
        }
        return make_pair(totflow, totcost);
    }
};

string t, s;
ll freq[30];

void getf(string &s)
{
	memset(freq,0,sizeof freq);

	for(auto it: s)
	{
		freq[it - 'a']++;
	}
}

ll fnode[30];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	MinCostMaxFlow flow(151);

	fastio;

	cin >> t;

	getf(t);

	for(ll i = 0; i < 26; i++)
	{
		flow.AddEdge(1,i + 2, freq[i], 0);
	}

	cin >> n;

	for(ll i = 1; i <= n; i++)
	{
		cin >> s >> input;

		getf(s);

		flow.AddEdge(i + 30, 150, input, i);

		for(ll j = 0; j < 26; j++)
		{
			flow.AddEdge(j + 2, i + 30, freq[j], 0);
		}
	}

	pll ans = flow.GetMaxFlow(1,150);

//	cout << ans.first << " " << ans.second << endl;

	if(ans.first < t.size()) cout << "-1\n";
	else cout << ans.second << "\n";

}


