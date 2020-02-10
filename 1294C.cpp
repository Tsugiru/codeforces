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

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<int, int> p;
        int count = 0;
        for(int i = 2; i * i <= n; i++) {
            while(n % i == 0) {
                count++;
                n /= i;
                p[i]++;
            }
        }
        if(n > 1) {
            p[n]++;
            count++;
        }
        if(count < 3) {
            cout << "NO" << endl;
            continue;
        }

        int a = begin(p)->first;
        if(--p[a] == 0) p.erase(a);
        int b = rbegin(p)->first;
        if(--p[b] == 0) p.erase(b);

        if(b == a) {
            b *= begin(p)->first;
            --(begin(p)->second);
        }

        int c = 1;
        for(auto &elem : p) {
            for(int i = 0; i < elem.second; i++) c *= elem.first;
        }

        if(c == 1 || c == a || c == b) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
    }
}