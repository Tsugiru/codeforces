#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
 
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
    size_t operator()(pii x) const {
        return int_hash{}(x.first) ^ (int_hash{}(x.second) << 16);
    }
};
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<cd> vcd;
typedef vector<vector<int>> vvi;
typedef vector<vvi> vvvi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
typedef unordered_map<int, int, int_hash> umii;
typedef unordered_map<ll, ll, int_hash> umll;
typedef unordered_set<int, int_hash> usi;
typedef unordered_set<ll, int_hash> usll;
typedef unordered_set<pii, pair_hash> uspii;
typedef queue<int> qi;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const int inf = numeric_limits<int>::max();
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n; cin >> n;
    vvvi mp(n + 1);
    umii occ;

    F0R(i, n - 2) {
        int a, b, c; cin >> a >> b >> c;
        occ[a]++; occ[b]++; occ[c]++;
        mp[a].pb({a, b, c});
        mp[b].pb({b, a, c});
        mp[c].pb({c, a, b});
    }
 
    int pos = 1, pos2 = 1, prev = 1;
    while(occ[pos] != 1) pos++;
    prev = mp[pos][0][0];
    pos = (occ[mp[prev][0][1]] == 2 ? mp[prev][0][1] : mp[prev][0][2]);
    pos2 = (occ[mp[prev][0][2]] == 3 ? mp[prev][0][2] : mp[prev][0][1]);

    cout << prev << " " << pos << " " << pos2;
 
    for(int i = 0; i < n - 3; i++) {
        int next = -1;
        for(auto &vec : mp[pos]) {
            if(find(all(vec), pos2) != end(vec)
                && find(all(vec), prev) == end(vec)) {
                next = vec[1] == pos2 ? vec[2] : vec[1];
            }
        }
        prev = pos;
        pos = pos2; 
        pos2 = next;
        if(next != -1) cout << " " << next;
    }
 
    cout << '\n';
}