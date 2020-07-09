#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const ll inf = 1e7;
const ll MX = 100001; //check the limits, dummy

ll compute_score(ll x, ll y, ll z) {
    return (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z);
}

ll getOrMax(vector<ll> &v, ll i) {
    return i < v.size() ? v[i] : numeric_limits<ll>::max();
}

ll getOrBack(vector<ll> &v, ll i) {
    return i < v.size() ? v[i] : v.back(); 
}

ll computeBestMid(const vector<ll> &v, ll x, ll y) {
    if(x > y) swap(x, y);

    ll res = numeric_limits<ll>::max();
    auto it = upper_bound(begin(v), end(v), (y - x) / 2 + x);
    if(it != end(v)) res = min(res, compute_score(x, y, *it));
    if(it != begin(v)) res = min(res, compute_score(x, y, *(--it)));

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t; cin >> t;
    while(t--) {
        ll nr, ng, nb; cin >> nr >> ng >> nb;

        vector<ll> vr(nr), vg(ng), vb(nb);

        for(ll &i : vr) cin >> i;
        for(ll &i : vg) cin >> i;
        for(ll &i : vb) cin >> i;

        sort(begin(vr), end(vr));
        sort(begin(vg), end(vg));
        sort(begin(vb), end(vb));

        ll r = 0, g = 0, b = 0;
        ll res = numeric_limits<ll>::max();
        vector<vector<ll>> vs{vr, vg, vb};
        while(r < nr || g < ng || b < nb) {
            ll wr = getOrBack(vr, r), wg = getOrBack(vg, g), wb = getOrBack(vb, b);
            res = min(res, compute_score(wr, wg, wb));

            vector<pair<ll, ll>> v {{wr, 0}, {wg, 1}, {wb, 2}};
            sort(begin(v), end(v));
            ll lst = v[1].second;
            res = min(res, computeBestMid(vs[lst], v[0].first, v[2].first));

            if(v[0].first == v[1].first) {
                lst = v[0].second;
                res = min(res, computeBestMid(vs[lst], v[1].first, v[2].first));
            }
            
            ll mn = min({getOrMax(vr, r), getOrMax(vg, g), getOrMax(vb, b)});
            if(r < nr && mn == vr[r]) r++;
            else if(g < ng && mn == vg[g]) g++;
            else if(b < nb && mn == vb[b]) b++;
        }

        cout << res << endl;
    }
}