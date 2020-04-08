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

const string week = "frcfcrffrcfcrffrcfcrf";
int a, b, c;

ll f(int i) {
    int qa = a / 3;
    int qb = b / 2;
    int qc = c / 2;
    int qm = min(qa, min(qb, qc));

    int ra = a - qm * 3;
    int rb = b - qm * 2;
    int rc = c - qm * 2;

    int j = i;
    while(ra >= 0 && rb >= 0 && rc >= 0) {
        ra -= week[j] == 'f';
        rb -= week[j] == 'r';
        rc -= week[j] == 'c';
        j++;
    }
    
    return j - i - 1 + qm * 7;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;
    ll best = 0;
    for(int i = 0; i < 7; i++)
        best = max(best, f(i));
    cout << best << endl;
}