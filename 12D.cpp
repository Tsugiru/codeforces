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
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
typedef vector<vvi> vvvi;
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

struct bit {
    vll tree;
    bit(int size) : tree(size + 1, 0) {}

    ll read(int i) {
        ll sum = 0;
        while(i) {
            sum = max(sum, tree[i]);
            i -= (i & -i);
        }
        return sum;
    }

    void update(int i, ll val) {
        while(i < sz(tree)) {
            tree[i] = max(val, tree[i]);
            i += (i & -i);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<tuple<int, int, int>> v(n, {0, 0, 0});
    vi xx(n, 0);

    F0R(i, n) cin >> get<0>(v[i]);
    F0R(i, n) cin >> get<1>(v[i]);
    F0R(i, n) cin >> get<2>(v[i]);
    F0R(i, n) xx[i] = get<1>(v[i]);
    sort(all(v));
    sort(all(xx));

    int ans = 0, prev = n - 1;
    bit b(n);
    F0Rd(i, n) {
        while(i < prev && get<0>(v[i]) < get<0>(v[i + 1])) {
            int x = lower_bound(all(xx), get<1>(v[prev])) - begin(xx);
            b.update(n - x, get<2>(v[prev]));
            prev--;
        }
        int x = lower_bound(all(xx), get<1>(v[i])) - begin(xx);
        if(b.read(n - x - 1) > get<2>(v[i])) ans++;
    }

    cout << ans << endl;
}