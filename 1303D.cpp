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

int l2(int v) {
    static const unsigned int b[] = {0xAAAAAAAA, 0xCCCCCCCC, 0xF0F0F0F0, 
                                    0xFF00FF00, 0xFFFF0000};
    unsigned int r = (v & b[0]) != 0;
    for (int i = 4; i > 0; i--) // unroll for speed...
    {
        r |= ((v & b[i]) != 0) << i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        ll n, m; cin >> n >> m;
        vector<int> v(64, 0);
        for(int i = 0; i < m; i++) {
            ll in; cin >> in;
            v[l2(in)]++;
        }
        
        for(int i = 0; i < 64; i++) {
            v[i + 1] += v[i] / 2;
            v[i] = v[i] & 1;
        }

        for(int i = 0; i < 32; i++) {
            if(n & (i << 1))
            for(int j )
        }
    }
}