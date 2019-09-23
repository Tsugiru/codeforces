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

ll calc(ll x) {
    ll ans = 0;
    for(ll i = 0; i < x; i *= 10, i += 9) {
        ans += (x - i) * (x - i + 1) / 2;
    }
    return ans;
}

ll calc2(ll x) {
    ll ans = 0;
    for(ll i = 0; i <= x; i *= 10, i += 9) {
        ans += (x - i);
    }
    return ans;
}

ll dig(ll x) {
    ll ans = 0;
    while(x) x /= 10, ans++;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll q; cin >> q;
    while(q--) {
        ll k; cin >> k;
        ll lo = 0, hi = 1e9;
        while(hi - lo > 1) {
            ll mid = lo + (hi - lo) / 2;
            if(calc(mid) >= k) hi = mid;
            else lo = mid;
        }

        ll r = k - calc(lo);
        lo = 0, hi = 1e9;
        while(hi - lo > 1) {
            ll mid = lo + (hi - lo) / 2;
            if(calc2(mid) >= r) hi = mid;
            else lo = mid;
        }

        r = r - calc2(lo);
        cout << (hi / (ll)pow(10,(dig(hi) - r))) % 10 << endl;
    }
}