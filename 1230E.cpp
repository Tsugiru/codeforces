#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

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
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int inf = 1e9;
const int MX = 100001; //check the limits, dummy

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

ll dfs(vvi &t, umpll &mp, vll &b, int i, int p) {
    umpll mpc;
    ll res = b[i];
    for(pll x : mp) {
        ll g = gcd(x.f, b[i]);
        mpc[g] += x.s;
        res = (res + (g * x.s) % MOD) % MOD;
    }
    mpc[b[i]]++;

    for(int nxt : t[i]) {
        if(nxt != p) res = (res + dfs(t, mpc, b, nxt, i)) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vll b(n, 0);
    F0R(i, n) cin >> b[i];            

    vvi t(n, vi());
    F0R(i, n - 1) {
        int a, b; cin >> a >> b; a--; b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }

    umpll mp;
    cout << dfs(t, mp, b, 0, -1) << endl;
}