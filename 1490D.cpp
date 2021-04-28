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

void f(int l, int r, const vector<int> &v, vector<int> &res, int lvl) {
    if(l > r) {
        return;
    }
    int m = max_element(begin(v) + l, begin(v) + r + 1) - begin(v);
    res[m] = lvl;
    f(l, m - 1, v, res, lvl + 1);
    f(m + 1, r, v, res, lvl + 1);
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int &i : v) cin >> i;
    vector<int> res(n);
    f(0, n - 1, v, res, 0);
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