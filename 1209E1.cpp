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
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vvi v(n, vi(m, 0));
        F0R(i, n) F0R(j, m) cin >> v[i][j];

        vpi best(n);
        int sub = 0;
        F0R(i, n) best[i] = {i, 0};
        F0R(i, m) {
            F0R(j, n) {
                auto it = min_element(all(best), [&](const pi& lhs, const pi &rhs){ return v[lhs.first][lhs.second] < v[rhs.first][rhs.second]; });
                if(v[it->first][it->second] < v[j][i] && find(all(best), mp(j, i)) == best.end()) *it = {j, i};
                else if(v[it->first][it->second] > v[j][i] && v[j][i] > sub) sub = v[j][i];
            }
        }

        int ans = accumulate(all(best), 0, [&](int sum, const pi &cur) { return sum + v[cur.first][cur.second]; });
        sort(all(best), [](const pi &lhs, const pi &rhs){ return lhs.second < rhs.second; });
        if(n == 4 && best[0].second == best[1].second && best[2].second == best[3].second && best[0].second != best[2].second){
            int dist1 = abs(best[0].first - best[1].first);
            int dist2 = abs(best[2].first - best[3].first);
            if(((dist1&1) & (dist2&1)) == 0) {
                auto it = min_element(all(best), [&](const pi& lhs, const pi &rhs){ return v[lhs.first][lhs.second] < v[rhs.first][rhs.second]; });
                ans -= v[it->first][it->second];
                ans += sub;
            }
        }

        cout << ans << endl; 
    }
    return 0;
}