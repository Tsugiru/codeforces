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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

vector<ll> factors(ll x) {
    vector<ll> result;
    for(ll i = 2; i * i <= x; i++) {
        while(x % i == 0) {
            x /= i;
            if(result.empty() || result.back() != i)
                result.push_back(i);
        }
    }
    if(x > 1 && (result.empty() || result.back() != x)) 
        result.push_back(x);
    return result;
}

ll solve(ll m) {
    vector<ll> pf = factors(m);
    ll limit = (1 << pf.size());

    ll ans = 0;
    for(ll i = 0; i < limit; i++) {
        ll product = 1;
        for(int j = 0; j < pf.size(); j++)
            if(i & (1 << j)) product *= pf[j];
        ans += (__builtin_popcountll(i) & 1) 
            ? -(m - 1)/product
            : (m - 1)/product;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        ll a, m; cin >> a >> m;
        ll d = gcd(a, m);
        m /= d;
        cout << solve(m) << endl;
    }
}