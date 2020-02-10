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

    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for(auto &vv : v)
        for(int &i : vv) {
           cin >> i;
           i--;
        }

    int ans = 0;
    for(int i = 0; i < m; i++) {
        vector<int> shift(n, n);
        for(int j = 0; j < n; j++) {
            int pos = v[j][i] / m;
            if(v[j][i] % m == i && pos < n)
                shift[(j - pos + n) % n]--;
        }
        
        int best = n;
        for(int j = 0; j < shift.size(); j++) {
            best = min(best, shift[j] + j);
        }

        ans += best;        
    }

    cout << ans << endl;
}