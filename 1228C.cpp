#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<cd> vcd;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const int MX = 100001;  //check the limits, dummy

vl sieve(ll x) {
    vl p(sqrt(x) + 1, 0), res;
    p[0] = p[1] = 1;
    F0R(i, sz(p)) {
        if (p[i]) continue;
        for (ll j = i * i; j < sz(p); j += i) p[j] = 1;
        if (x % i == 0) res.pb(i);
    }
    if (sz(res) == 1) res.pb(x / res[0]);
    if (sz(res) == 0) res.pb(x);
    return res;
}

ll fstpow(ll x, ll y) {
    ll res = 1, cur = x;
    while (y) {
        if (y & 1) res = (res * cur) % MOD;
        cur = (cur * cur) % MOD;
        y >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x;
    ll n;
    cin >> x >> n;
    vl primes = sieve(x);

    ll ans = 1;
    for (ll p : primes) {
        ll y = 0, cur = p;
        while (cur <= n && ()) {
            y += n / cur;
            cur *= p;
        }
        ans = (ans * fstpow(p, y)) % MOD;
    }

    cout << ans << endl;
}