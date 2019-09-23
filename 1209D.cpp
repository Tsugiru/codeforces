#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int dfs(vector<int> &visited, vector<vector<int>> &g, int i) {
    int ans = 0;
    if(!visited[i]) {
        visited[i] = 1;
        for(auto k : g[i]) ans += dfs(visited, g, k);
        ans++;
    }
    return ans;
}

int main() {
    int n, k; cin >> n >> k;
    int ans = 0;
    vpii v(k, {0, 0});
    vvi g(n, vector<int>());
    vi visited(n, 0);

    for(int i = 0; i < k; i++) {
        cin >> v[i].first >> v[i].second;
        g[v[i].first - 1].push_back(v[i].second - 1);
        g[v[i].second - 1].push_back(v[i].first - 1);
    }

    for(int i = 0; i < n; i++)
        if(!visited[i]) 
            ans += dfs(visited, g, i) - 1;

    cout << k - ans << endl;
    return 0;
}