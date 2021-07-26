// Complexity: O(n*m)


ll n, k;
vector<vector<ll>> g;
vector<ll> mt;
vector<bool> used;

bool try_kuhn(ll v) {
    if (used[v])
        return false;
    used[v] = true;
    for (ll to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}


void kuhn
{
    mt.assign(k, -1);
    vector<bool> used1(n, false);
    for (ll v = 0; v < n; ++v) {
        for (ll to : g[v]) {
            if (mt[to] == -1) {
                mt[to] = v;
                used1[v] = true;
                break;
            }
        }
    }
    for (ll v = 0; v < n; ++v) {
        if (used1[v])
            continue;
        used.assign(n, false);
        try_kuhn(v);
    }

    for (ll i = 0; i < k; ++i)
        if (mt[i] != -1)
            printf("%d %d\n", mt[i] + 1, i + 1);
}
