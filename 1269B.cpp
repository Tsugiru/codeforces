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

int solve_fast(vector<int> &a, vector<int> &b, int m) {
    int n = a.size();

    vector<int> kmp(n, 0);
    for(int i = 1, j = 0; i < n; i++) {
        while(j > 0 && a[i] - a[i - 1] != a[j] - a[j - 1])
            j = kmp[j - 1];
        kmp[i] = ++j;
    }

    b.insert(end(b), begin(b), end(b));
    int ans = inf;
    for(int i = 0, j = 0, x = 0; i < 2*n; i++) {
        while(j > 0 && (b[i] - a[j] + m) % m != x) {
            j = kmp[j - 1];
            x = (b[i - 1] - a[j - 1] + m) % m;
        }
        x = (b[i] - a[j] + m) % m;
        j++;
        if(j == n) {
            ans = min(ans, x);
            j = kmp[j - 1];
            x = (b[i] - a[j - 1] + m) % m;
        }
    }

    return ans;
}

int solve_slow(vector<int> &a, vector<int> &b, int m) {
    int n = a.size(), ans = m;
    for(int i = 0; i < n; i++) {
        int diff = (b[0] - a[i] + m) % m;
        int j = 1;
        while(j < n && (b[j] - a[(i + j) % n] + m) % m == diff) j++;
        if(j == n) {
            ans = min(ans, diff);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(begin(a), end(a));
    sort(begin(b), end(b));

    cout << solve_fast(a, b, m) << endl;
}