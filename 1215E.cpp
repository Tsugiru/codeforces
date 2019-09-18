#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
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
    int n; cin >> n;
    vvi v(20, vi());
    vvl cnt(20, vl(20, 0));
    F0R(i, n) {
        int in; cin >> in;
        v[--in].pb(i);
    }

    F0R(col1, 20) {
        F0R(col2, 20) {
            if(col1 == col2) continue;
            int j = 0;
            F0R(i, sz(v[col1])) {
                while(j < sz(v[col2]) && v[col2][j] < v[col1][i]) j++;
                cnt[col1][col2] += j;
            }
        }
    }
    
    vl dp(1 << 20, INF);
    dp[0] = 0;
    F0R(i, 1 << 20) {
        F0R(j, 20) {
            if(i & (1 << j)) {
                ll sum = 0;
                F0R(k, 20) {
                    if(i & (1 << k)) sum += cnt[j][k];
                }
                dp[i] = min(dp[i], dp[i ^ (1 << j)] + sum);
            }
        }
    }

    cout << dp.back() << endl;
    return 0;    
}