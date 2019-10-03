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
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        vvc v(2, vc(n, 0));
        F0R(i, 2) F0R(j, n) cin >> v[i][j];
        
        vvi t(3, vi(n + 1, 0)), b(3, vi(n + 1, 0));
        t[1][0] = 1;
        FOR(i, 1, n + 1) {
            if(v[0][i - 1] <= '2') {
                t[1][i] = t[1][i - 1];
            }
            else {
                t[2][i] = t[1][i - 1];
            }

            if(v[1][i - 1] <= '2') {
                b[1][i] = b[1][i - 1];
            }
            else {
                b[0][i] = b[1][i - 1];
                b[1][i] = t[2][i];
            }
            
            if(v[0][i - 1] > '2') {
                t[1][i] = b[0][i];
            }
        }

        cout << (b[1][n] ? "YES" : "NO") << endl;
    }
}