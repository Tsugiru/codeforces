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

pii dfs_v(vvi &v, vi &c, vi &b, int i) {
    int res = 0, cnt = 0;
    if(!c[i]) {
        c[i] = 1;
        F0R(j, sz(v[i])) {
            pii ret = dfs_v(v, c, b, v[i][j]);
            res += ret.f;
            cnt += ret.s;
        }
        res += b[i];
        cnt++;
    }
    return {res, cnt};
}

int dfs(vvi &v, vi &b) {
    vi c(sz(v), 0);
    int res = 0, cnt = 0;
    F0R(i, sz(v)) {
        if(!c[i]) { 
            pii ret = dfs_v(v, c, b, i);
            res = max(res, ret.f);
            cnt = max(cnt, ret.s);
        }
    }
    return cnt >= 2 ? res : 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vpll a(n, {0, 0});
    F0R(i, n) cin >> a[i].f;
    F0R(i, n) cin >> a[i].s;

    sort(begin(a), end(a));
    vi t(n, 0);
    int i = n - 1;
    ll res = 0;
    while(i >= 0) {
        if(i != 0 && a[i].f == a[i - 1].f) {
            ll cur = a[i].f;
            while(i >= 0 && a[i].f == cur) {
                res += a[i].s;
                t[i] = 1;
                i--;
            }
        }
        else {
            FOR(j, i + 1, n) {
                if(t[j] && !((a[i].f ^ a[j].f) & a[i].f)) {
                    res += a[i].s;
                    t[i] = 1;
                    break;
                }
            }
            i--;
        } 
    }

    cout << res << endl;
}