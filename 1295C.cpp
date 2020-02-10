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

int check(vector<vector<int>> &v, string &t) {
    int m = t.size(), ans = 0;
    for(int i = 0, cur = 0; i < m; i++) {
        cur = v[cur][t[i] - 'a'];
        if(cur == -1) {
            cur = v[0][t[i] - 'a'];
            ans++;
            if(cur == -1) return -1;
        }
    }
    return ans + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        string s, t; cin >> s >> t;
        int n = s.size();
        vector<vector<int>> v(n + 1, vector<int>(26, -1));
        vector<int> cur(26, -1);
        for(int i = n; i >= 0; i--) {
            for(int j = 0; j < 26; j++) v[i][j] = cur[j];
            if(i != 0) cur[s[i - 1] - 'a'] = i;
        }

        cout << check(v, t) << endl;
    }
}