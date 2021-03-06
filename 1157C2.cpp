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

    int n; cin >> n;
    vector<int> v(n);
    for(int &i : v) cin >> i;

    int b = 0, l = 0, r = n - 1;
    string res;
    while(l <= r && v[l] != v[r] && (v[l] > b || v[r] > b)) {
        int lval = v[l] > b ? v[l] : inf;
        int rval = v[r] > b ? v[r] : inf;
        if(lval < rval) {
            b = lval;
            l++;
            res += "L";
        }
        else {
            b = rval;
            r--;
            res += "R";
        }
    }
    if(v[l] == v[r] && v[l] > b) {
        int ll = l + 1, rr = r - 1;
        while(ll < r && v[ll] > v[ll - 1]) ll++;
        while(rr > l && v[rr] > v[rr + 1]) rr--;

        res += ll - l > r - rr ? string(ll - l, 'L') : string(r - rr, 'R');
    }

    cout << res.size() << endl;
    cout << res << endl;
}