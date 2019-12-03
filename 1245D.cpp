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

int cost(vpii &v, vi &k, int i, int j) {
    return (k[i] + k[j])*(abs(v[i].f - v[j].f) + abs(v[i].s - v[j].s));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vpii v(n, {0, 0});
    vi c(n, 0), k(n, 0);
    F0R(i, n) cin >> v[i].f >> v[i].s;
    F0R(i, n) cin >> c[i];
    F0R(i, n) cin >> k[i];

    vi g(n, 0);
    vi l(n, 0);
    vi p;
    usi b;
    vpii res;
    int cur = 1, ans = 0;
    F0R(i, n) {
        int best = !i;
        F0R(j, n) {
            if(i == j) continue;
            if(cost(v, k, i, j) < cost(v, k, i, best)) {
                best = j;
            }
        }
        if(cost(v, k, i, best) < c[i]) {
            if(g[best] == 0) {
                if(l[best]) b.insert(cur);
                g[best] = cur++;
            }
            g[i] = g[best];
            res.pb({i, best});
            ans += cost(v, k, i, best);
        }
        else {
            l[i] = 1;
            p.pb(i);
            ans += c[i];
        }
    }

    FOR(i, 1, cur) {
        if(!b.count(i)) {
            int min1 = inf;
            int ind = 0;
            int min2 = inf;
            pii a = {0, 0};
            F0R(j, n) {
                if(g[j] == i) {
                    if(c[j] < min1) {
                        min1 = c[j];
                        ind = j;
                    }
                    F0R(q, n) {
                        if(g[q] != i) {
                            if(cost(v, k, q, j) < min2) {
                                min2 = cost(v, k, q, j);
                                a = {q, j};
                            }
                        }
                    }
                }
            }
            if(min1 < min2) {
                p.pb(ind);
                ans += min1;
            }
            else {
                res.pb({a.f, a.s});
                ans += min2; 
            }
        }
    }

    cout << ans << endl;
    cout << sz(p) << endl;
    F0R(i, sz(p)) {
        cout << p[i] + 1;
        cout << (i == sz(p) - 1 ? "\n" : " ");
    }
    cout << sz(res) << endl;
    F0R(i, sz(res)) cout << res[i].f << " " << res[i].s << endl;
}