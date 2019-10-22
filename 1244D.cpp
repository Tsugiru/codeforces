#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define sz(x) (int)(x).size()
#define pb push_back
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
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
typedef unordered_map<int, int, int_hash> umpii;
typedef unordered_map<ll, ll, int_hash> umpll;
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
    vvl cs(n, vll(3, 0));
    for(int i = 0; i < n; i++) cin >> cs[i][0];
    for(int i = 0; i < n; i++) cin >> cs[i][1];
    for(int i = 0; i < n; i++) cin >> cs[i][2];

    vvi v(n, vi());
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        v[a].pb(b);
        v[b].pb(a);
        if(sz(v[a]) > 2 || sz(v[b]) > 2) {
            cout << -1 << endl;
            return 0;
        }
    }

    int start = 0;
    for(int i = 0; i < n; i++) {
        if(sz(v[i]) == 1) start = i;
    }
    qi q; q.push(start);
    vi nodes;
    vi c(n, 0); c[start] = 1;
    while(!q.empty()) {
        int cur = q.front();
        nodes.pb(cur);
        q.pop();

        for(int next : v[cur]) {
            if(!c[next]) {
                q.push(next);
                c[next] = 1;
            }
        }
    }

    vi colors{0, 1, 2}, best;
    ll ans = INF;
    do {
        ll sum = 0;
        for(int i = 0; i < sz(nodes); i++) {
            if(i % 3 == 0) sum += cs[nodes[i]][colors[0]];
            if((i - 1) % 3 == 0) sum += cs[nodes[i]][colors[1]];
            if((i - 2) % 3 == 0) sum += cs[nodes[i]][colors[2]];
        }
        if(sum < ans) {
            ans = sum;
            best = colors;
        }
    }
    while(next_permutation(colors.begin(), colors.end()));

    cout << ans << endl;
    vi w(n, 0);
    for(int i = 0; i < sz(nodes); i++) {
        if(i % 3 == 0) w[nodes[i]] = best[0] + 1;
        if((i - 1) % 3 == 0) w[nodes[i]] = best[1] + 1;
        if((i - 2) % 3 == 0)  w[nodes[i]] = best[2] + 1;
    }
    for(int i : w) cout << i << " ";
    cout << '\n';
}