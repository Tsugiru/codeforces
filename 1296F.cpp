#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

struct int_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct pair_hash {
    size_t operator()(pair<int, int> x) const {
        return int_hash{}(x.first) ^ (int_hash{}(x.second) << 16);
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const int inf = 1e7;
const int MX = 100001; //check the limits, dummy

void dfs(int node, int prev, const vector<vector<int>> &g, vector<int> &p, vector<int> &vis) {
    if(!vis[node]) {
        vis[node] = 1;
        p[node] = prev;
        for(auto next : g[node]) {
            dfs(next, node, g, p, vis);
        }
    }
}

bool solve() {
    int n; cin >> n;
    vector<pair<int, int>> edges;
    unordered_map<pair<int, int>, int, pair_hash> costs;
    vector<vector<int>> g(n);

    for(int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        edges.emplace_back(x, y);
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    int m; cin >> m;
    vector<vector<int>> queries(m, vector<int>(3));
    for(auto &v : queries) {
        cin >> v[0] >> v[1] >> v[2];
        v[0]--; v[1]--;
    }
    sort(begin(queries), end(queries), [](const vector<int> &lhs, const vector<int> &rhs) {
        return lhs[2] > rhs[2];
    });

    for(int i = 0; i < m; i++) {
        int x = queries[i][0], y = queries[i][1], c = queries[i][2];

        vector<int> p(n, -1), vis(n, 0);
        dfs(x, -1, g, p, vis);
        
        bool ok = false;
        while(p[y] != -1) {
            int l = min(y, p[y]), r = max(y, p[y]);
            if(!costs.count({l, r}) || costs[{l, r}] == c) {
                costs[{l, r}] = c;
                ok = true;
            }
            y = p[y];
        }

        if(!ok) return false;
    }

    for(auto &p : edges) {
        int l = min(p.first, p.second), r = max(p.first, p.second);
        cout << (costs.count({l, r}) ? costs[{l, r}] : 1) << " ";
    }
    cout << endl;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if(!solve()) cout << -1 << endl;
}