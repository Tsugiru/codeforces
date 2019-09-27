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
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<cd> vcd;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
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

int check(vi &l, vvi &v) {
    vvi c(6, vi(6, 0));
    int n = l.size(), ans = 0;
    F0R(i, n) {
        F0R(j, sz(v[i])) {
            int lo = min(l[i], l[v[i][j]]);
            int hi = max(l[i], l[v[i][j]]);
            if(c[lo][hi] != 1) {
                c[lo][hi] = 1;
                ans++;
            }
        }
    }
    return ans;
}

int f(vi &l, vvi &v, int i) {
    if(i == sz(l)) {
        return check(l, v);
    }
    else {
        int res = 0;
        F0R(j, 6) {
            l[i] = j;
            res = max(res, f(l, v, i + 1));
        }
        return res;
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    vvi v(n, vi());
    F0R(i, m) {
        int x, y; cin >> x >> y; x--; y--;
        v[x].pb(y);
        v[y].pb(x); 
    }

    vi l(n, 0);
    cout << f(l, v, 0) << endl;     
}