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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s; cin >> s;
    vector<set<int>> v(26, set<int>());
    F0R(i, sz(s)) v[s[i] - 'a'].insert(i);

    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int pos; char c; cin >> pos >> c;
            pos--;
            v[s[pos] - 'a'].erase(pos);
            v[c - 'a'].insert(pos);
            s[pos] = c;
        }
        else {
            int l, r; cin >> l >> r;
            l--; r--;
            int ans = 0;
            F0R(i, 26) {
                auto it = v[i].lb(l);
                if(it != v[i].end() && *it <= r) ans++;
            }
            cout << ans << endl;
        }
    }
}
