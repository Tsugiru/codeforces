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

int get(int x, int cand) {
    return x == -1 ? cand : x;
}

int test(vector<int> &a, int cand) {
    int mx = 0;
    for(int i = 1; i < a.size(); i++) {
        mx = max(mx, abs(get(a[i], cand) - get(a[i - 1], cand)));
    }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int &i : a) cin >> i;

        int fne = 0;
        while(fne < n && a[fne] == -1) fne++;
        if(fne == n) {
            cout << 0 << " " << 0 << endl;
            continue;
        }

        vector<ll> p;
        for(int i = 0; i < n - 1; i++) {
            if(a[i + 1] == -1 && a[i] != -1) p.push_back(a[i]);
            else if(a[i] == -1 && a[i + 1] != -1) p.push_back(a[i + 1]);
        }

        ll mx = *max_element(begin(p), end(p));
        ll mn = *min_element(begin(p), end(p));
        ll cand = (mx + mn) / 2;
        int x = test(a, cand), y = test(a, cand + 1);
        if(x < y) cout << x << " " << cand << endl;
        else cout << y << " " << cand + 1 << endl;
    }
}