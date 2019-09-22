#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<ll, ll> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<cd> vcd;
typedef vector<vector<ll>> vvi;
typedef vector<vector<ll>> vvl;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FORd(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (ll i = (a)-1; i >= 0; i--)

#define sz(x) (ll)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x1, y1, x2, y2;
    ll x3, y3, x4, y4;
    ll x5, y5, x6, y6;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;

    ll xi1 = max(x1, x3), xi2 = min(x2, x4), yi1 = max(y1, y3), yi2 = min(y4, y2);
    ll xi3 = max(x1, x5), xi4 = min(x2, x6), yi3 = max(y1, y5), yi4 = min(y2, y6);
    ll xii1 = max(xi1, xi3), xii2 = min(xi2, xi4), yii1 = max(yi1, yi3), yii2 = min(yi4, yi2);
    
    cout << (max(0LL, (xi2 - xi1)) * max(0LL, (yi2 - yi1)) + max(0LL, (xi4 - xi3)) * max(0LL, (yi4 - yi3)) 
            - max(0LL, (xii2 - xii1)) * max(0LL, (yii2 - yii1)) < (x2 - x1) * (y2 - y1) ? "YES" : "NO") << endl;
}