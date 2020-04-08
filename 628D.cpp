#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

const ll MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const ll inf = 1e7;
const ll MX = 100001; //check the limits, dummy

ll dp[2001][2001][2];

ll f(const string &s, ll m, ll d) {
    int n = s.size();
    fill_n(&dp[0][0][0], 2001*2001*2, 0);

    dp[0][0][0] = dp[0][0][1] = 1;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 0; j < m; j++) {
            for(ll k = 0; k < 2; k++) {
                ll cur = s[n - i] - '0';
                if((n - i) & 1) {
                    if(k == 0 && d > cur) dp[i][j][k] = 0;
                    else dp[i][j][k] = dp[i - 1][(j * 10 + d) % m][k | d < cur];
                }
                else {
                    for(ll q = 0; q <= (k ? 9 : cur); q++) {
                        if(q == d) continue;
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][(j * 10 + q) % m][k | q < cur]) % MOD;
                    }
                }
            }
        }
    }

    return dp[n][0][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll m, d; cin >> m >> d;
    string a; cin >> a;
    string b; cin >> b;

    ll q = a.find_last_not_of("0");
    for(ll i = a.size(); i > q; i--) a[i] = '9';
    a[q]--;

    cout << (f(b, m, d) - f(a, m, d) + MOD) % MOD << endl;
}