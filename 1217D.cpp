#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
auto pair_hash = [](const auto &p) { return p.first ^ p.second << 16; };
typedef unordered_map<pair<int, int>, int, decltype(pair_hash)> umpiii;

void dfs_v(int i, int prev, vi &result, vvi &g, umpiii &order, vi &visited, int &color) {
    if(visited[i] == 1) color = result[order[{prev, i}]] = 2;
    else if(prev != -1 && visited[i] == 2) result[order[{prev, i}]] = 1;
    else {
        visited[i] = 1;
        if(prev != -1) result[order[{prev, i}]] = 1;
        for(auto &next : g[i]) {
            dfs_v(next, i, result, g, order, visited, color);
        }
        visited[i] = 2;
    }
}

void dfs(vi &result, vvi &g, umpiii &order, int &color) {
    vi visited(g.size(), 0);
    for(int i = 0; i < g.size(); i++) {
        if(!visited[i])
            dfs_v(i, -1, result, g, order, visited, color);
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    umpiii order(m, pair_hash);
    vector<int> result(m);

    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v; u--; v--;
        g[u].push_back(v);
        order[{u, v}] = i;
    }

    int color = 0;
    dfs(result, g, order, color);
    if(color) cout << 2 << endl;
    else cout << 1 << endl;

    for(auto &i : result) cout << i << " ";
    cout << endl;
}