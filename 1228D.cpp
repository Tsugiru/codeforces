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
typedef vector<vector<ll>> vvl;
typedef unordered_map<int, int> umpii;
typedef unordered_map<ll, ll> umpll;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
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

    int n, m;
    cin >> n >> m;
    uspii s;
    vvi g(n, vi());
    F0R(i, m) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].pb(b);
        g[b].pb(a);
        s.insert({a, b});
        s.insert({b, a});
    }

    vi c(n, 0), cnt(3, 0);
    FOR(i, 1, 4) {
        int j = 0;
        while(j < n && c[j] != 0) j++;
        if(j == n) {
            cout << -1 << endl;
            return 0;
        }
        c[j] = i;
        cnt[i - 1]++;
        F0R(q, n) {
            if(q != j && !s.count({j, q})) {
                c[q] = i;
                cnt[i - 1]++;
            }
        }
    }
    if(count(c.begin(), c.end(), 0)) {
        cout << -1 << endl;
        return 0;
    }
    F0R(i, n) {
        if(c[i] == 1 && sz(g[i]) != cnt[1] + cnt[2]
        || c[i] == 2 && sz(g[i]) != cnt[0] + cnt[2]
        || c[i] == 3 && sz(g[i]) != cnt[0] + cnt[1]) {
            cout << -1 << endl;
            return false;
        }
        F0R(j, sz(g[i])) {
            if(c[g[i][j]] == c[i]) {
                cout << -1 << endl;
                return false;
            }
        }
    }    
    for(int i : c) cout << i << " ";
    cout << '\n';
}