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

bool solve(vector<vector<int>> &result, vector<int> &mp, const int n) {
    int x = 0, y = 0;
    for(int i = 1; i < mp.size() && y < n/2; i++) {
        while(mp[i] >= 4 && y < n/2) {
            result[x][y] = result[x][n - y - 1] 
                = result[n - x - 1][y] = result[n - x -1][n - y - 1] = i;
            mp[i] -= 4;
            y += ((x + 1) % (n/2) == 0);
            x = (x + 1) % (n/2);
        }
    }
    if(y != n/2) return false;
    if(n % 2 == 1) {
        for(int i = 1, midv = 0, midh = 0; i < mp.size(); i++) {
            if(mp[i] % 2 != 0) {
                if(result[n/2][n/2] != 0) return false;
                else result[n/2][n/2] = i;
                mp[i]--;
            }
            while(mp[i]) {
                if(midv < n/2) result[n/2][midv++] = result[n/2][n - midv - 1] = i;
                else result[midh++][n/2] = result[n - midh - 1][n/2] = i;
                mp[i] -= 2;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<int> mp(1001, 0);
    for(int i = 0, in = 0; i < n * n; i++) {
        cin >> in;
        mp[in]++;
    }
    vector<vector<int>> result(n, vector<int>(n, 0));
    if(solve(result, mp, n)) {
        cout << "YES" << endl;
        for(auto &v : result) {
            for(int i : v) cout << i << " ";
            cout << endl;
        }
    }
    else cout << "NO" << endl;
}