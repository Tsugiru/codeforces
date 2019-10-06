#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<pi> vpi;
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
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    int n, k; cin >> n >> k;
    string v; cin >> v; 

    vi pre(n, -1);
    for(int i = 0, j = 0; i < n; i++) {
        while(j < n && (v[j] != '1' || i - j > k)) j++;
        if(j < n && abs(i - j) <= k) pre[i] = j;
    }
    
    vll dp(n + 1, INF); dp[0] = 0;
    for(int i = 1; i <= v.size(); i++) {
        dp[i] = min(dp[i], dp[i - 1] + i);
        if(pre[i - 1] != -1) dp[i] = min(dp[i], dp[max(0, pre[i - 1] - k)] + pre[i - 1] + 1);
    }
    cout << dp.back() << endl;
}