#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <chrono>
#include <random>
#include <string>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>

using namespace std;
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

void solve() {
    int n; cin >> n;
    vector<pair<ll, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(rbegin(v), rend(v));
    ll s = accumulate(begin(v) + 1, end(v), 0LL, [](ll so_far, const auto &i) { 
        return so_far + i.first; 
    });
    vector<int> res {v[0].second};
    for(int i = 1; i < n && s >= v[i - 1].first; i++) {
        res.push_back(v[i].second);
        s -= v[i].first;
    }
    sort(begin(res), end(res));
    cout << res.size() << endl;
    for(int &i : res) cout << i << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        solve();
    }
}