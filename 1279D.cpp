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

const int MOD = 998244353;
const ll INF = numeric_limits<ll>::max();
const int inf = numeric_limits<int>::max();
const int MX = 100001; //check the limits, dummy

int gcdExtended(int a, int b, int *x, int *y)  
{  
    if(a == 0) {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
  
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);  
  
    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return gcd;  
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct frac {
    ll num, den;
    frac(ll num, ll den) : num(num), den(den) {}
    frac operator+(const frac &other) {
        ll ret_num = ((num * other.den) % MOD + (den * other.num) % MOD) % MOD;
        ll ret_den = (den * other.den) % MOD;
        return {ret_num, ret_den};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n; cin >> n;
    unordered_map<int, int> cnt;
    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        while(k--) {
            int x; cin >> x;
            cnt[x]++;
            v[i].push_back(x);
        }
    }
    
    frac ans{0, 1};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < v[i].size(); j++) {
            ll num = cnt[v[i][j]];
            ll den = (((n * n) % MOD) * v[i].size()) % MOD;
            ans = ans + frac{ num, den };
        }
    }

    ll x = ans.num, y = ans.den;
    int g = gcd(x, y);
    x /= g; y /= g;
    int minv1 = 0, minv2 = 0;
    gcdExtended(y, MOD, &minv1, &minv2);
    minv1 = (minv1 % MOD + MOD) % MOD;

    cout << (x * minv1) % MOD << endl;
}