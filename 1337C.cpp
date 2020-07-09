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

int dfs(vector<int> &v, int i, const vector<vector<int>> &g, int p, int dist) {
    int des = 0;
    for(int next : g[i]) {
        if(next != p) {
            des += dfs(v, next, g, i, dist + 1) + 1;
        }
    }
    v.push_back(dist - des);
    return des;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; cin >> n >> k;

    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> v;
    dfs(v, 0, g, -1, 0);
    ll sum = 0;
    sort(begin(v), end(v));
    for(int i = v.size() - k; i < v.size(); i++) sum += v[i];
    cout << sum << endl;
}