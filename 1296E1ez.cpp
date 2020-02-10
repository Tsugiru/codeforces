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
    string s; cin >> s;
    char cur = s[0];
    vector<int> cols(n, 0);
    cols[0] = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] >= cur) {
            cur = s[i];
            cols[i] = 1;
        }
    }

    int prev = -1;
    bool good = true;
    for(int i = 0; i < n; i++) {
        if(cols[i] == 0 && prev == -1) prev = i;
        else if(cols[i] == 0 && prev != -1) {
            if(s[prev] > s[i]) {
                good = false;
                break;
            }
            prev = i;
        }
    }
 
    if(!good) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for(int i : cols) cout << i;
        cout << endl;
    }
}