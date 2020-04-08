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

vector<int> f1(int a, int b, int c, vector<int> &s) {
    int ca = 0, cc = 0;
    if(b <= a) {
        ca = a - b;
        a = b;
    }
    else {
        auto it = upper_bound(begin(s), end(s), a);
        int next = *it, prev = *(--it);
        ca = min(abs(a - next), abs(a - prev));
        a = ca == abs(a - next) ? next : prev;
    }

    if(c < b) {
        cc = b - c;
        c = b;
    }
    else {
        int rc = c % b;
        cc = min(rc, b - rc);
        c = cc == rc ? c - rc : c + b - rc;
    }
    
    return {a, b, c, ca + cc}; 
}

vector<int> d(int x) {
    vector<int> res;
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            res.push_back(i);
            if(x / i != i) res.push_back(x / i);
        }
    }

    sort(begin(res), end(res));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> divs;
    for(int i = 1; i <= 20000; i++)
        divs.push_back(d(i));

    int t; cin >> t;
    while(t--) {
        int a, b, c; cin >> a >> b >> c;
        int r1 = b % a, t2 = c % b;

        vector<int> sol{0, 0, 0, numeric_limits<int>::max()};
        for(int i = 1; i <= 2*c; i++) {
            vector<int> tmp = f1(a, i, c, divs[i - 1]);
            tmp[3] += abs(b - i);
            if(tmp[3] < sol[3]) sol = tmp;
        }

        cout << sol[3] << endl;
        cout << sol[0] << " " << sol[1] << " " << sol[2] << endl;
    }
}