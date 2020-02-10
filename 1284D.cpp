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

struct st {
    vector<int> tree;

    st(int size, int val) : tree(4*size, val) {}

    void update_min(int val, int index, int node, int l, int r) {
        if(index >= l && index <= r) {
            tree[node] = min(tree[node], val);
            if(r - l > 0) {
                int mid = (r - l) / 2 + l;
                update_min(val, index, 2*node, l, mid);
                update_min(val, index, 2*node + 1, mid + 1, r);
            }
        }
    }

    void update_max(int val, int index, int node, int l, int r) {
        if(index >= l && index <= r) {
            tree[node] = max(tree[node], val);
            if(r - l > 0) {
                int mid = (r - l) / 2 + l;
                update_max(val, index, 2*node, l, mid);
                update_max(val, index, 2*node + 1, mid + 1, r);
            }
        }
    }

    int query_min(int li, int ri, int node, int l, int r) {
        if(l >= li && r <= ri) return tree[node];
        else if(min(ri, r) - max(li, l) >= 0) {
            int mid = (r - l) / 2 + l;
            return min(query_min(li, ri, 2*node, l, mid),
                       query_min(li, ri, 2*node + 1, mid + 1, r));
        }
        else return inf;
    }

    int query_max(int li, int ri, int node, int l, int r) {
        if(l >= li && r <= ri) return tree[node];
        else if(min(ri, r) - max(li, l) >= 0) {
            int mid = (r - l) / 2 + l;
            return max(query_max(li, ri, 2*node, l, mid),
                       query_max(li, ri, 2*node + 1, mid + 1, r));
        }
        else return 0;
    }
};

bool check(vector<vector<int>> &v) {
    int n = v.size();
    st mnst(n, inf), mxst(n, 0);

    sort(begin(v), end(v));
    for(int i = 0; i < n; i++) {
        mxst.update_max(v[i][2], i, 1, 0, n - 1);
        mnst.update_min(v[i][3], i, 1, 0, n - 1);
    }

    for(int i = 0; i < n - 1; i++) {
        int lo = i + 1, hi = n - 1;
        if(v[lo][0] <= v[i][1]){
            if(v[hi][0] <= v[i][1]) {
                lo = hi;
            }
            else {
                while(hi - lo > 1) {
                    int mid = (hi - lo) / 2 + lo;
                    if(v[mid][0] > v[i][1]) hi = mid;
                    else lo = mid;
                }
            }
            int mx = mxst.query_max(i + 1, lo, 1, 0, n - 1);
            int mn = mnst.query_min(i + 1, lo, 1, 0, n - 1);

            if(mx > v[i][3] || mn < v[i][2]) return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;

    vector<vector<int>> v1(n, vector<int>(4));
    vector<vector<int>> v2(n, vector<int>(4));
    for(int i = 0; i < n; i++) {
        cin >> v1[i][0] >> v1[i][1] >> v1[i][2] >> v1[i][3];
        v2[i] = v1[i];
        swap(v2[i][0], v2[i][2]);
        swap(v2[i][1], v2[i][3]);
    }


    cout << (check(v1) && check(v2) ? "YES" : "NO") << endl;
}