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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;

        unordered_map<pair<int, int>, int, pair_hash> mp;
        unordered_map<char, pair<int, int>> dirs 
        {
            {'U', {1, 0}},
            {'D', {-1, 0}},
            {'L', {0, -1}},
            {'R', {0, 1}}
        };

        int x = 0, y = 0;
        int l = 0, r = 0, best = inf;
        bool ok = false;
        for(int i = 0; i < n; i++) {
            if(mp.count({x, y})) {
                if(best > i - mp[{x, y}]) {
                    best = i - mp[{x, y}];
                    r = i;
                    l = mp[{x, y}] + 1;
                    ok = true;
                }
            }
            mp[{x, y}] = i;
            x += dirs[s[i]].first;
            y += dirs[s[i]].second;
        }
        if(mp.count({x, y})) {
            if(best > n - mp[{x, y}]) {
                best = n - mp[{x, y}];
                r = n;
                l = mp[{x, y}] + 1;
                ok = true;
            }
        }

        if(ok) cout << l << " " << r << endl;
        else cout << -1 << endl;
    }
}