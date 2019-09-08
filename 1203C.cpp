#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll a_gcd(vector<ll>& v) {
    ll g = 0;
    for(ll i = 0; i < v.size(); i++) g = gcd(g, v[i]);
    return g;
}

int main() {
    ll n; cin >> n;
    vector<ll> v(n, 0);
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll g = a_gcd(v), ans = 0;
    for(ll i = 1; i <= sqrt(g); i++) {
        if(g % i == 0) ans += (g/i == i ? 1 : 2);
    }
    cout << ans << endl;
}