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
const int inf = 2e9;
const int MX = 100001; //check the limits, dummy

int computeIntersectionWithout(const vector<pair<int, int>> &v, int k) {
    int l = 0, r = inf;
    for(int i = 0; i < v.size(); i++) {
        if(i == k) continue;
        l = max(l, v[i].first);
        r = min(r, v[i].second);
    }
    return r - l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    int l = 0, r = inf;
    unordered_map<int, vector<int>, int_hash> ls, rs;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++)  {
        int li, ri; cin >> li >> ri;
        ls[li].push_back(i);
        rs[ri].push_back(i);
        l = max(l, li);
        r = min(r, ri);
        v.push_back({li, ri});
    }

    if(ls[l].size() > 1 && rs[r].size() > 1) cout << max(0, r - l) << endl;
    else if(ls[l].size() > 1) cout << max(0, computeIntersectionWithout(v, rs[r][0])) << endl;
    else if(rs[r].size() > 1) cout << max(0, computeIntersectionWithout(v, ls[l][0])) << endl;
    else cout << max(0, max(computeIntersectionWithout(v, ls[l][0]), 
                    computeIntersectionWithout(v, rs[r][0]))) << endl;
}